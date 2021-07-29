//
// Created by paula on 6/20/2021.
//

#include "AstronomerWindow.h"

AstronomerWindow::AstronomerWindow(RepoStars &stars, Astronomer &astronomer): stars{stars}, a{astronomer} {
    this->stars.addObserver(this);
    this->initGUI();
    this->connectSignals();
    this->show();
}

void AstronomerWindow::initGUI() {
    QFont buttonsFont("Consolas", 13, true);

    this->tableModel = new TableModel{this->stars};
    this->starsTableView = new QTableView{};
    this->starsTableView->setModel(this->tableModel);

    this->starsListWidget = new QListWidget{};
    this->starsListWidget->setFont(buttonsFont);

    this->constellationCheckBox = new QCheckBox();
    this->constellationCheckBox->setText("Show only your constellation");
    this->constellationCheckBox->setFont(buttonsFont);

    this->searchLineEdit = new QLineEdit();
    this->searchLineEdit->setFont(buttonsFont);

    this->nameLineEdit = new QLineEdit();
    this->nameLineEdit->setFont(buttonsFont);

    this->raLineEdit = new QLineEdit();
    this->raLineEdit->setFont(buttonsFont);

    this->decLineEdit = new QLineEdit();
    this->decLineEdit->setFont(buttonsFont);

    this->diameterLineEdit = new QLineEdit();
    this->diameterLineEdit->setFont(buttonsFont);

    this->addButton = new QPushButton{"Add"};
    this->addButton->setFont(buttonsFont);

    this->viewButton = new QPushButton{"View constellation"};
    this->viewButton->setFont(buttonsFont);

    this->mainLayout =  new QVBoxLayout();

    this->buttonsLayout = new QGridLayout();

    QLabel* textStarName = new QLabel();
    textStarName->setText("Star's name: ");
    textStarName->setFont(buttonsFont);

    QLabel* textName = new QLabel();
    textName->setText("Name");
    textName->setFont(buttonsFont);

    QLabel* raText = new QLabel();
    raText->setText("Right Ascension");
    raText->setFont(buttonsFont);

    QLabel* decText = new QLabel();
    decText->setText("Declination");
    decText->setFont(buttonsFont);

    QLabel* diameterText = new QLabel();
    diameterText->setText("Diameter");
    diameterText->setFont(buttonsFont);

    this->buttonsLayout->addWidget(this->starsTableView, 0, 0);
    this->buttonsLayout->addWidget(this->starsListWidget, 0, 1);
    this->buttonsLayout->addWidget(textStarName, 1, 0);
    this->buttonsLayout->addWidget(this->searchLineEdit, 1, 1);
    this->buttonsLayout->addWidget(textName, 2, 0);
    this->buttonsLayout->addWidget(this->nameLineEdit, 2, 1);
    this->buttonsLayout->addWidget(raText, 3, 0);
    this->buttonsLayout->addWidget(this->raLineEdit, 3, 1);
    this->buttonsLayout->addWidget(decText, 4, 0);
    this->buttonsLayout->addWidget(this->decLineEdit, 4, 1);
    this->buttonsLayout->addWidget(diameterText, 5, 0);
    this->buttonsLayout->addWidget(this->diameterLineEdit, 5, 1);
    this->buttonsLayout->addWidget(this->addButton);
    this->buttonsLayout->addWidget(this->viewButton);
    this->buttonsLayout->addWidget(this->constellationCheckBox);

    this->mainLayout->addLayout(buttonsLayout);

    this->setLayout(this->mainLayout);
    this->setWindowTitle(QString::fromStdString(a.getName()));
    this->resize(700,500);
}

void AstronomerWindow::connectSignals() {
    QObject::connect(this->addButton, &QPushButton::clicked, this, &AstronomerWindow::addStar);
    QObject::connect(this->constellationCheckBox, &QCheckBox::stateChanged, this, &AstronomerWindow::filterConstellations);
    QObject::connect(this->viewButton, &QPushButton::clicked, this, &AstronomerWindow::openApplication);
    QObject::connect(this->searchLineEdit, &QLineEdit::textChanged, this, &AstronomerWindow::filterStarName);
}

void AstronomerWindow::notifyModel() {
    this->tableModel->update_data_in_real_time();
}

int AstronomerWindow::getSelectedIndex() {
    QModelIndexList selectedIndexes = this->starsTableView->selectionModel()->selectedIndexes();
    if(selectedIndexes.isEmpty())
        return -1;
    int selectedIndex=selectedIndexes.at(0).row();
    return selectedIndex;
}

void AstronomerWindow::update() {
    this->notifyModel();
}

void AstronomerWindow::filterConstellations() {
    if (this->constellationCheckBox->isChecked()) {
        string constellation = this->a.getConstellation();
        QSortFilterProxyModel* proxyModel = new QSortFilterProxyModel{};            // OR with a function for filter in service etc. ...
        proxyModel->setSourceModel(this->tableModel);
        this->starsTableView->setSortingEnabled(true);
        proxyModel->setFilterFixedString(QString::fromStdString(constellation));
        proxyModel->setFilterKeyColumn(1);
        this->starsTableView->setModel(proxyModel);
    }
    else {
        TableModel* model = new TableModel{this->stars};
        this->starsTableView->setModel(model);
    }
}

void AstronomerWindow::filterStarName() {
    string starName = this->searchLineEdit->text().toStdString();
    vector<Star> filtered = this->stars.filterStarsByName(starName);
    this->populateList(filtered);
}

void AstronomerWindow::addStar() {
    string name = this->nameLineEdit->text().toStdString();
    int ra = this->raLineEdit->text().toInt();
    int dec = this->decLineEdit->text().toInt();
    int diameter = this->diameterLineEdit->text().toInt();
    string constellation = this->a.getConstellation();
    if (diameter < 0) {
        QMessageBox::critical(this, "Error", "Invalid diameter!");
        return;
    }
    for (auto& s : this->stars.getAll())
        if (s.getName() == name) {
            QMessageBox::critical(this, "Error", "Invalid name!");
            return;
        }
    Star s(name, constellation, ra, dec, diameter);
    this->stars.addStar(s);
}

void AstronomerWindow::populateList(vector<Star> stars) {
    this->starsListWidget->clear();
    for (auto& s : stars)
        this->starsListWidget->addItem(QString::fromStdString(s.getName() + "|" + s.getConstellation() + "|" + to_string(s.getRA()) + "|" + to_string(s.getDec()) + "|" + to_string(s.getDiameter())));
}

void AstronomerWindow::openApplication() {
    int index = this->getSelectedIndex();
    if (index != -1) {
        Star s = this->stars.getAll()[index];
        ConstellationWindow *cw = new ConstellationWindow(this->stars, s);
        cw->show();
    }
    else {
        QMessageBox::critical(this, "Error", "Please select a constellation!");
        return;
    }
}

AstronomerWindow::~AstronomerWindow() {
    this->stars.removeObserver(this);
}
