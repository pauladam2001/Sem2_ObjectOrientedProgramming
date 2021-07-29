//
// Created by paula on 6/20/2021.
//

#include "ProgrammerWindow.h"

ProgrammerWindow::ProgrammerWindow(Files &files, Programmer &p): files{files}, p{p} {
    this->files.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

void ProgrammerWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->nrLeftFilesLabel = new QLabel{};
    this->nrLeftFilesLabel->setFont(buttonsFont);
    this->nrLeftFilesLabel->setText(QString::number(this->p.getTotalFiles() - this->p.getNrRevisedFiles()));

    this->nrReviewedFilesLabel = new QLabel{};
    this->nrReviewedFilesLabel->setFont(buttonsFont);
    this->nrReviewedFilesLabel->setText(QString::number(this->p.getNrRevisedFiles()));

    QLabel* textReviewed = new QLabel();
    textReviewed->setText("Number of revised files: ");
    textReviewed->setFont(buttonsFont);

    QLabel* textLeftFiles = new QLabel();
    textLeftFiles->setText("Number of files that still need to be revised: ");
    textLeftFiles->setFont(buttonsFont);

    this->reviseFileButton = new QPushButton{"Revise file"};
    this->reviseFileButton->setFont(buttonsFont);
    this->reviseFileButton->setEnabled(false);

    this->addFileButton = new QPushButton{"Add file"};
    this->addFileButton->setFont(buttonsFont);

    this->fileNameLineEdit = new QLineEdit{};
    this->fileNameLineEdit->setFont(buttonsFont);

    this->tableModel = new TableModel(this->files);
    this->sourceFilesTableView = new QTableView{};

    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
    proxyModel->setSourceModel(this->tableModel);
    this->sourceFilesTableView->setSortingEnabled(true);
    proxyModel->sort(0, Qt::AscendingOrder);
    this->filterModel = proxyModel;

    this->sourceFilesTableView->setModel(proxyModel);

    this->mainLayout = new QVBoxLayout{};
    this->mainLayout->addWidget(this->sourceFilesTableView);

    this->buttonsLayout = new QGridLayout{};
    this->buttonsLayout->addWidget(this->fileNameLineEdit, 0, 0);
    this->buttonsLayout->addWidget(this->addFileButton, 0, 1);
    this->buttonsLayout->addWidget(textReviewed, 1, 0);
    this->buttonsLayout->addWidget(this->nrReviewedFilesLabel, 1, 1);
    this->buttonsLayout->addWidget(textLeftFiles, 2, 0);
    this->buttonsLayout->addWidget(this->nrLeftFilesLabel, 2, 1);

    this->mainLayout->addLayout(this->buttonsLayout);
    this->mainLayout->addWidget(this->reviseFileButton);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->p.getName()));
    this->resize(700, 500);
}

void ProgrammerWindow::update() {
    this->notifyModel();
    this->nrReviewedFilesLabel->setText(QString::number(this->p.getNrRevisedFiles()));
    if (this->p.getTotalFiles() == this->p.getNrRevisedFiles())
        this->nrLeftFilesLabel->setText(QString::number(0));
    else
        this->nrLeftFilesLabel->setText(QString::number(this->p.getTotalFiles() - this->p.getNrRevisedFiles()));
}

void ProgrammerWindow::notifyModel() {
    this->tableModel->update_data_in_real_time();
}

int ProgrammerWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->sourceFilesTableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}

void ProgrammerWindow::checkIfReviseAvailable() {
    int index = this->getSelectedIndex();
    string status = this->filterModel->index(index, 1).data().toString().toStdString();
    string creator = this->filterModel->index(index, 2).data().toString().toStdString();
    if (status == "not-revised" && creator != this->p.getName())
        this->reviseFileButton->setEnabled(true);
    else
        this->reviseFileButton->setEnabled(false);
}

void ProgrammerWindow::revise() {
    int index = this->getSelectedIndex();
    string name = this->filterModel->index(index, 0).data().toString().toStdString();
    string status = this->filterModel->index(index, 1).data().toString().toStdString();
    string creator = this->filterModel->index(index, 2).data().toString().toStdString();
    string reviewer = this->filterModel->index(index, 3).data().toString().toStdString();
    SourceFile f(name, status, creator, reviewer);
    string namee = this->p.getName();
    this->p.setNrRevisedFiles(this->p.getNrRevisedFiles() + 1);
    this->files.makeRevised(f, name);
    this->reviseFileButton->setDisabled(true);
    if (this->p.getNrRevisedFiles() == this->p.getTotalFiles()) {
        QMessageBox::information(this, "Congratulations!", "Congratulations! You've revised all your files!");
        return;
    }
}

void ProgrammerWindow::connectSignals() {
    QObject::connect(this->addFileButton, &QPushButton::clicked, this, &ProgrammerWindow::addSourceFile);
    QObject::connect(this->reviseFileButton, &QPushButton::clicked, this, &ProgrammerWindow::revise);
    QObject::connect(this->sourceFilesTableView, &QTableView::clicked, this, &ProgrammerWindow::checkIfReviseAvailable);
}

void ProgrammerWindow::addSourceFile() {
    string sourceFileName = this->fileNameLineEdit->text().toStdString();
    if (sourceFileName.empty()) {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->fileNameLineEdit->setText("");
    for (auto &f : this->files.getAll()) {
        if (f.getName() == sourceFileName) {
            QMessageBox::critical(this, "Error", "Invalid input!");
            return;
        }
    }
    string name = this->p.getName();
    SourceFile f(sourceFileName, name);
    this->files.add_sourceFile(f);
}

ProgrammerWindow::~ProgrammerWindow() {
    this->files.removeObserver(this);
}
