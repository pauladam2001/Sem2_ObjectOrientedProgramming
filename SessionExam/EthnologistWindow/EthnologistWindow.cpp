//
// Created by paula on 6/22/2021.
//

#include "EthnologistWindow.h"

EthnologistWindow::EthnologistWindow(Service &service, Ethnologist &e, QWidget *parent): service{service}, e{e}, QWidget(parent) {
    this->service.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

void EthnologistWindow::initGUI() {
    this->setPalette(QPalette(QColor(rand()%255,rand()%255,rand()%255)));
    this->setWindowTitle(QString::fromStdString(this->e.getName()));
    this->resize(1000,700);

    this->tableModel = new TableModel(this->service, this->e);
    this->buildingsTableView = new QTableView{};
    this->buildingsTableView->setModel(this->tableModel);

//    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
//    proxyModel->setSourceModel(this->tableModel);
//    this->buildingsTableView->setSortingEnabled(true);
//    proxyModel->sort(2, Qt::AscendingOrder);
//    this->buildingsTableView->setModel(proxyModel);

    this->mainLayout = new QVBoxLayout{};
    this->mainLayout->addWidget(this->buildingsTableView);

    this->addButton = new QPushButton("Add building");
    this->updateButton = new QPushButton("Update building");

    this->descriptionLineEdit = new QLineEdit{};
    this->locationsLineEdit = new QLineEdit{};

    QLabel* descriptionLabel = new QLabel{};
    descriptionLabel->setText("Description:");

    QLabel* locationsLabel = new QLabel{};
    locationsLabel->setText("Locations:");

    this->descriptionUpdateLineEdit = new QLineEdit{};
    this->locationsUpdateLineEdit = new QLineEdit{};

    QLabel* descriptionUpdateLabel = new QLabel{};
    descriptionUpdateLabel->setText("New description:");

    QLabel* locationsUpdateLabel = new QLabel{};
    locationsUpdateLabel->setText("New locations:");

    this->buttonsLayout = new QGridLayout{};
    this->buttonsLayout->addWidget(descriptionLabel, 0, 0);
    this->buttonsLayout->addWidget(this->descriptionLineEdit, 0, 1);
    this->buttonsLayout->addWidget(locationsLabel, 1, 0);
    this->buttonsLayout->addWidget(this->locationsLineEdit, 1, 1);
    this->buttonsLayout->addWidget(this->addButton, 2, 0, 1, 2);

    this->buttonsLayout->addWidget(descriptionUpdateLabel, 0, 3);
    this->buttonsLayout->addWidget(this->descriptionUpdateLineEdit, 0, 4);
    this->buttonsLayout->addWidget(locationsUpdateLabel, 1, 3);
    this->buttonsLayout->addWidget(this->locationsUpdateLineEdit, 1, 4);
    this->buttonsLayout->addWidget(this->updateButton, 2, 3, 1, 2);

    this->mainLayout->addLayout(this->buttonsLayout);

    this->buildingsTableView->resizeColumnsToContents();

    this->setLayout(mainLayout);
}

void EthnologistWindow::connectSignals() {
    QObject::connect(this->addButton, &QPushButton::clicked, this, &EthnologistWindow::add_building);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &EthnologistWindow::update_building);
}

void EthnologistWindow::notifyModel() {
    this->tableModel->update_data_in_real_time();
}

void EthnologistWindow::update() {
    this->notifyModel();
}

void EthnologistWindow::add_building() {
    string description = this->descriptionLineEdit->text().toStdString();
    string location = this->locationsLineEdit->text().toStdString();

    if (description.empty() || location.empty()) {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }

    try {
        this->service.add_building(description, this->e.getArea(), location);
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;;
    }
}

int EthnologistWindow::get_selected_index() {
    QModelIndexList selectedIndexes = this->buildingsTableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}

void EthnologistWindow::update_building() {
    string description = this->descriptionUpdateLineEdit->text().toStdString();
    string location = this->locationsUpdateLineEdit->text().toStdString();

    int index = this->get_selected_index();
    int id = this->tableModel->index(index, 0).data().toInt();

    if (description.empty() || location.empty()) {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }

    try {
        this->service.update_building(id, description, location);
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Invalid input!");
    }
}

EthnologistWindow::~EthnologistWindow() {
    this->service.removeObserver(this);
}
