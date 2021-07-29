//
// Created by Alexandra on 6/21/2021.
//

#include "UserWindow.h"

UserWindow::UserWindow(Service &service, User &u, QWidget *parent):service{service}, u{u}, QWidget(parent) {
    this->service.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

UserWindow::~UserWindow() {

}

void UserWindow::update() {
this->notifyModel();
if(this->currentIndexTableView != -1) {
        this->answersListWidget->clearSelection();
        this->answersListWidget->clear();
        Question q = this->service.getQuestions()[this->currentIndexTableView];
        vector<Answer> answers = this->service.getAnswersForQuestion(q);
        for (auto &a: answers) {
            QListWidgetItem *item = new QListWidgetItem(
                    QString::fromStdString(a.getID() + "|" + a.getName() + "|" + a.getText() + "|" +
                                           to_string(a.getNrVotes())));
            if (a.getName() == this->u.getName()) {
                item->setBackground(Qt::yellow);
            }
            this->answersListWidget->addItem(item);

        }
    }
}


void UserWindow::notifyModel() {
    this->tableModel->updateInternalData();
}

void UserWindow::initGUI() {

    QFont buttonsFont("Consolas", 13, true);

    this->questionsTableView = new QTableView();
    this->tableModel = new TableModel(this->service);

    this->questionsTableView->setModel(this->tableModel);
    this->questionsTableView->resizeColumnsToContents();

    this->answersListWidget = new QListWidget{};
    this->answersListWidget->setFont(buttonsFont);

    this->voteSpinBox = new QSpinBox();
    this->voteSpinBox->setFont(buttonsFont);

    this->addQuestionButton = new QPushButton("Add question!");
    this->addQuestionButton->setFont(buttonsFont);

    this->addAnswerButton = new QPushButton("Add answer!");
    this->addAnswerButton->setFont(buttonsFont);

    this->answerLineEdit = new QLineEdit();
    this->answerLineEdit->setFont(buttonsFont);

    this->questionTextLineEdit = new QLineEdit();
    this->questionTextLineEdit->setFont(buttonsFont);

    QLabel* question = new QLabel("Question text");
    question->setFont(buttonsFont);

    QLabel* answer = new QLabel("Answer");
    answer->setFont(buttonsFont);

    this->buttonsLayout = new QGridLayout();
    this->mainLayout = new QVBoxLayout();

    this->buttonsLayout->addWidget(this->questionsTableView, 0, 0);
    this->buttonsLayout->addWidget(this->answersListWidget, 0, 1);
    this->buttonsLayout->addWidget(this->voteSpinBox, 0, 2);

    this->buttonsLayout->addWidget(question, 1, 0);
    this->buttonsLayout->addWidget(this->questionTextLineEdit, 1, 1);
    this->buttonsLayout->addWidget(this->addQuestionButton, 1, 2);

    this->buttonsLayout->addWidget(answer, 2, 0);
    this->buttonsLayout->addWidget(this->answerLineEdit, 2, 1);
    this->buttonsLayout->addWidget(this->addAnswerButton, 2, 2);

    this->mainLayout->addLayout(this->buttonsLayout);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(this->u.getName()));
    this->resize(1700,800);


}

void UserWindow::connectSignals() {
    QObject::connect(this->addQuestionButton, &QPushButton::clicked, this, &UserWindow::addQuestion);
    QObject::connect(this->addAnswerButton, &QPushButton::clicked, this, &UserWindow::addAnswer);
    QObject::connect(this->questionsTableView, &QTableView::clicked, this, &UserWindow::populateList);
    QObject::connect(this->answersListWidget, &QListWidget::itemClicked, this, &UserWindow::changeQSpinBox);
//    QObject::connect(this->voteSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &UserWindow::voteAnswer);
//    QObject::connect(this->voteSpinBox, SIGNAL(valueChanged(int)), this, SLOT(voteAnswer(int)));
}

void UserWindow::initAnswersGUI() {

}

void UserWindow::addQuestion() {
    string text = this->questionTextLineEdit->text().toStdString();
    if(text.empty()){
        QMessageBox::critical(this, "Error", "Invalid text for question!");
        return;
    }
    this->service.addQuestion(text, this->u.getName());
    QMessageBox::information(this, "Question added!", "Question added!");
}

void UserWindow::addAnswer() {
    string answer = this->answerLineEdit->text().toStdString();
    if(answer.empty()){
        QMessageBox::critical(this, "Error", "Invalid answer!");
        return;
    }
    Question q = this->service.getQuestions()[this->questionsTableView->currentIndex().row()];
    string questionID = q.getID();
    this->service.addAnswer(answer, this->u.getName(), questionID);
    QMessageBox::information(this, "Answer added!", "Answer added!");
}

void UserWindow::populateList() {
    this->currentIndexTableView = QPersistentModelIndex(this->questionsTableView->currentIndex()).row();
    disconnect(this->myConnect);
    this->answersListWidget->clearSelection();
    int nrVotes = 0;
    this->answersListWidget->clear();
    Question q = this->service.getQuestions()[this->currentIndexTableView];
    vector<Answer> answers = this->service.getAnswersForQuestion(q);
    for(auto & a: answers){
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(a.getID() + "|" + a.getName() + "|" + a.getText() + "|" +
                                                                                   to_string(a.getNrVotes())));
        if(a.getName() == this->u.getName()){
            item->setBackground(Qt::yellow);
        }
        nrVotes += a.getNrVotes();
        this->answersListWidget->addItem(item);

    }
    this->voteSpinBox->setValue(nrVotes);
    this->connectSignals2();
}

void UserWindow::voteAnswer() {
    Question q = this->service.getQuestions()[this->currentIndexTableView];
    vector<Answer> answers = this->service.getAnswersForQuestion(q);
    int index = this->getSelectedIndexList();
    if(index == -1){
        QMessageBox::critical(this, "Error", "Please select the answer you want to vote!");
        return;
    }
    Answer a = answers[index];
    int nrVotes = this->voteSpinBox->text().toInt();
    this->service.updateNrVotes(a, nrVotes);

}

void UserWindow::changeQSpinBox() {
    Question q = this->service.getQuestions()[this->currentIndexTableView];
    vector<Answer> answers = this->service.getAnswersForQuestion(q);
    int index = this->getSelectedIndexList();
    Answer a = answers[index];
    disconnect(this->myConnect);
    this->voteSpinBox->setValue(a.getNrVotes());
    this->connectSignals2();
}

int UserWindow::getSelectedIndexList() {
    QModelIndexList selectedIndexes = this->answersListWidget->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
    {
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void UserWindow::connectSignals2() {
    this->myConnect = connect(this->voteSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
                     this, &UserWindow::voteAnswer);
}
