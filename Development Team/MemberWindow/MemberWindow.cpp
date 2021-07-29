//
// Created by paula on 6/20/2021.
//

#include "MemberWindow.h"


MemberWindow::MemberWindow(Service &service, Member &m): service{service}, m{m} {
    this->service.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

void MemberWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->tableModel = new TableModel(this->service);
    this->issuesTableView = new QTableView{};

    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
    proxyModel->setSourceModel(this->tableModel);
    this->issuesTableView->setSortingEnabled(true);
    proxyModel->sort(0, Qt::AscendingOrder);
    proxyModel->sort(1, Qt::AscendingOrder);
    this->filterModel = proxyModel;

    this->issuesTableView->setModel(proxyModel);

    this->removeButton = new QPushButton("Remove");
    this->removeButton->setFont(buttonsFont);
    this->reportButton = new QPushButton("Report issue");
    this->reportButton->setFont(buttonsFont);
    this->resolveButton = new QPushButton("Resolve issue");
    this->resolveButton->setFont(buttonsFont);

    this->issuesLineEdit = new QLineEdit{};
    this->issuesTableView->setFont(buttonsFont);

    this->mainLayout = new QVBoxLayout{};
    this->buttonsLayout = new QGridLayout{};

    QLabel* descriptionLabel = new QLabel("Description");
    descriptionLabel->setFont(buttonsFont);

    this->mainLayout->addWidget(this->issuesTableView);

    this->buttonsLayout->addWidget(descriptionLabel, 0, 0);
    this->buttonsLayout->addWidget(this->issuesLineEdit, 0, 1);
    this->buttonsLayout->addWidget(this->reportButton, 0, 2);
    this->buttonsLayout->addWidget(this->removeButton, 1, 0);
    this->buttonsLayout->addWidget(this->resolveButton, 1, 1);

    this->mainLayout->addLayout(this->buttonsLayout);

    if (this->m.getType() == "programmer")
        this->reportButton->setEnabled(false);

    if (this->m.getType() == "tester")
        this->resolveButton->setEnabled(false);

    this->setLayout(this->mainLayout);

    string name = this->m.getName() + "-" + this->m.getType();
    this->setWindowTitle(QString::fromStdString(name));
//    this->resize(1200, 700);
}

void MemberWindow::connectSignals() {
    QObject::connect(this->reportButton, &QPushButton::clicked, this, &MemberWindow::reportIssue);
    QObject::connect(this->removeButton, &QPushButton::clicked, this, &MemberWindow::removeIssue);
    QObject::connect(this->resolveButton, &QPushButton::clicked, this, &MemberWindow::resolveIssue);
    QObject::connect(this->issuesTableView, &QTableView::clicked, this, &MemberWindow::check);
}

void MemberWindow::reportIssue() {
    string description = this->issuesLineEdit->text().toStdString();
    if (description.empty()) {
        QMessageBox::critical(this, "Error", "Invalid description!");
        return;
    }
    try {
        this->service.addIssue(description, "open", this->m.getName(), "-");
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "The given issue already exists!");
        return ;
    }
}

void MemberWindow::update() {
    this->notifyModel();
}

void MemberWindow::notifyModel() {
    this->tableModel->update_data_in_real_time();
}

void MemberWindow::removeIssue() {
    int index = this->getSelectedIndex();
    if (index == -1) {
        QMessageBox::critical(this, "Error", "Invalid selection!");
        return;
    }
    string description = this->filterModel->index(index, 0).data().toString().toStdString();
    string status = this->filterModel->index(index, 1).data().toString().toStdString();
    string reporter = this->filterModel->index(index, 2).data().toString().toStdString();
    string solver = this->filterModel->index(index, 3).data().toString().toStdString();
    Issue is(description, status, reporter, solver);
    if (is.getStatus() == "closed")
        this->service.deleteIssue(is);
    else {
        QMessageBox::critical(this, "Error", "This issue is not closed yet!");
        return;
    }
}

void MemberWindow::check() {
    int index = this->getSelectedIndex();
    string type = this->m.getType();
    if (type == "tester") {
        this->resolveButton->setEnabled(false);
        return;
    }
    else {
        string status = this->filterModel->index(index, 1).data().toString().toStdString();
        if (status == "closed") {
            this->resolveButton->setEnabled(false);
            return;
        }
        else {
            this->resolveButton->setEnabled(true);
            return;
        }
    }
}

void MemberWindow::resolveIssue() {
    int index = this->getSelectedIndex();
    string description = this->filterModel->index(index, 0).data().toString().toStdString();
    string status = this->filterModel->index(index, 1).data().toString().toStdString();
    string reporter = this->filterModel->index(index, 2).data().toString().toStdString();
    string solver = this->filterModel->index(index, 3).data().toString().toStdString();
    Issue is(description, status, reporter, solver);
    this->service.resolveIssue(is, this->m.getName());
}

int MemberWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->issuesTableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}

MemberWindow::~MemberWindow() {
    this->service.removeObserver(this);
}
