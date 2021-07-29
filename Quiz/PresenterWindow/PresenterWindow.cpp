//
// Created by paula on 6/21/2021.
//

#include "PresenterWindow.h"

PresenterWindow::PresenterWindow(RepoQuestion &repo, QWidget *parent): repo{repo}, QWidget(parent) {
    this->repo.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

void PresenterWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->questionsTableView = new QTableView();
    this->tableModel = new TableModelPresenter(this->repo);

    this->questionsTableView->setModel(this->tableModel);

    this->questionsTableView->resizeColumnsToContents();

    this->correctAnswerLineEdit = new QLineEdit();
    this->correctAnswerLineEdit->setFont(buttonsFont);

    this->idLineEdit = new QLineEdit();
    this->idLineEdit->setFont(buttonsFont);

    this->textLineEdit = new QLineEdit();
    this->textLineEdit->setFont(buttonsFont);

    this->correctAnswerLabel = new QLabel("Correct answer");
    this->correctAnswerLabel->setFont(buttonsFont);

    this->idLabel = new QLabel("ID");
    this->idLabel->setFont(buttonsFont);

    this->textLabel = new QLabel("Text");
    this->textLabel->setFont(buttonsFont);

    this->addButton = new QPushButton("Add question!");
    this->addButton->setFont(buttonsFont);

    this->mainLayout = new QVBoxLayout();
    this->buttonsLayout = new QGridLayout();

    this->mainLayout->addWidget(this->questionsTableView);

    this->buttonsLayout->addWidget(this->idLabel, 0, 0);
    this->buttonsLayout->addWidget(this->textLabel, 0, 1);
    this->buttonsLayout->addWidget(this->correctAnswerLabel, 0, 2);

    this->buttonsLayout->addWidget(this->idLineEdit, 1, 0);
    this->buttonsLayout->addWidget(this->textLineEdit, 1, 1);
    this->buttonsLayout->addWidget(this->correctAnswerLineEdit, 1, 2);

    this->mainLayout->addLayout(this->buttonsLayout);
    this->mainLayout->addWidget(this->addButton);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString("Presenter"));
    this->resize(700, 500);
}

void PresenterWindow::connectSignals() {
        QObject::connect(this->addButton, &QPushButton::clicked, this, &PresenterWindow::addQuestion);
}

void PresenterWindow::update() {
    this->notifyModel();
}

void PresenterWindow::notifyModel() {
    this->tableModel->updateInternalData();
}

void PresenterWindow::addQuestion() {
    int id = this->idLineEdit->text().toInt();
    string text = this->textLineEdit->text().toStdString();
    if (text.empty()) {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    string correctAnswer = this->correctAnswerLineEdit->text().toStdString();
    srand(time(nullptr));
    int score = rand() % 10;
    Question q(id, text, correctAnswer, score);
    try {
        this->repo.addQuestion(q);
    }
    catch (...) {
        QMessageBox::critical(this, "Error", "Invalid input!");
        return;
    }
    this->idLineEdit->clear();
    this->textLineEdit->clear();
    this->correctAnswerLineEdit->clear();
}

PresenterWindow::~PresenterWindow() {
    this->repo.removeObserver(this);
}
