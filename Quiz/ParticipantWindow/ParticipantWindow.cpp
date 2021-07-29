//
// Created by paula on 6/21/2021.
//

#include "ParticipantWindow.h"

ParticipantWindow::ParticipantWindow(RepoQuestion &repo, RepoParticipants &repoParticipants, Participant &p,
                                     QWidget *parent): repo{repo}, repoParticipants{repoParticipants}, p{p}, QWidget(parent) {
    this->repo.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

void ParticipantWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->questionsTableView = new QTableView();
    this->tableModel = new TableModel(this->repo);

    this->questionsTableView->setModel(this->tableModel);

//    QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};
//    proxyModel->setSourceModel(this->tableModel);
//    this->questionsTableView->setSortingEnabled(true);
//    proxyModel->sort(2, Qt::DescendingOrder);
//    this->questionsTableView->setModel(proxyModel);

    this->questionsTableView->resizeColumnsToContents();

    this->answerLineEdit = new QLineEdit();
    this->answerLineEdit->setFont(buttonsFont);

    this->answerLabel = new QLabel("Answer");
    this->answerLabel->setFont(buttonsFont);

    this->answerButton = new QPushButton("Answer the question");
    this->answerButton->setFont(buttonsFont);

    QLabel* score = new QLabel("Score: ");
    score->setFont(buttonsFont);

    this->scoreLabel = new QLabel();
    this->scoreLabel->setText(QString::fromStdString(to_string(this->p.getScore())));
    this->scoreLabel->setFont(buttonsFont);

    this->buttonsLayout = new QGridLayout();
    this->mainLayout = new QVBoxLayout();

    this->mainLayout->addWidget(this->questionsTableView);
    this->buttonsLayout->addWidget(this->answerLabel, 0, 0);
    this->buttonsLayout->addWidget(this->answerLineEdit, 0, 1);
    this->buttonsLayout->addWidget(this->answerButton, 0, 2);
    this->buttonsLayout->addWidget(score, 1, 0);
    this->buttonsLayout->addWidget(this->scoreLabel, 1, 1);

    this->mainLayout->addLayout(this->buttonsLayout);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->p.getName()));
    this->resize(700,500);
}

void ParticipantWindow::connectSignals() {
    QObject::connect(this->answerButton, &QPushButton::clicked, this, &ParticipantWindow::answerQuestion);
    QObject::connect(this->questionsTableView, &QTableView::clicked, this, &ParticipantWindow::checkIfAnswered);
}

void ParticipantWindow::notifyModel() {
    this->tableModel->update_data_in_real_time();
}

void ParticipantWindow::update() {
    this->notifyModel();
}

void ParticipantWindow::answerQuestion() {
    this->tableModel->addBackground(this->questionsTableView->currentIndex().row());
    string answer = this->answerLineEdit->text().toStdString();
    Question q = this->repo.getQuestions()[this->questionsTableView->currentIndex().row()];
    try {
        this->repoParticipants.updateParticipantScore(q, answer, this->p);
        QMessageBox::information(this, "Correct answer!", "Correct answer!");
        this->scoreLabel->setText(QString::number(this->p.getScore()));
        this->answerLineEdit->clear();
        return;
    }
    catch (...) {
        this->answerLineEdit->clear();
        QMessageBox::critical(this, "Wrong answer!", "Wrong answer! Zero point received!");
        return;
    }
}

void ParticipantWindow::checkIfAnswered(const QModelIndex &index) {
    auto color = this->tableModel->data(index, Qt::BackgroundRole);
    if (color == QColor(Qt::green))
        this->answerButton->setEnabled(false);
    else
        this->answerButton->setEnabled(true);
}

ParticipantWindow::~ParticipantWindow() {
    this->repo.removeObserver(this);
}
