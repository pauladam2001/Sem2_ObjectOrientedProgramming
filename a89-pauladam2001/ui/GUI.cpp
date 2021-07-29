//
// Created by paul on 5/3/2021.
//

#include "GUI.h"
#include "CSVBasket.h"
#include "HTMLBasket.h"
#include "../exceptions/customExceptions.h"
#include <vector>
#include "trenchCoat.h"

#include <QLabel>
#include <qlayout.h>
#include <QObject>
#include <QMainWindow>
#include <QDialog>
#include <QFormLayout>
#include <qmessagebox.h>
#include <QFont>
#include <QtCharts/QChart>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChartView>


GUI::GUI(Service &service, Validator &validator, UserService &userService, QWidget *parent): QMainWindow(parent), service{service}, validator{validator}, userService{userService} {
    this->init_fileType();
    this->connectSignalsAndSlots();
}

void GUI::init_fileType() {
    QFont fileTypeFont("Helvetica", 10, QFont::Bold);

    this->setWindowTitle("Trench coats shop");

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setFont(fileTypeFont);

    QVBoxLayout* fileTypeLayout = new QVBoxLayout();

    QLabel* fileTypeLabel = new QLabel();
    fileTypeLabel->setFont(fileTypeFont);
    fileTypeLabel->setText("Choose the type of file:");
    fileTypeLabel->show();

    fileTypeLayout->addWidget(fileTypeLabel);

    QGridLayout* buttonsLayout = new QGridLayout();

    this->CSVButton = new QPushButton();
    this->CSVButton->setFont(fileTypeFont);
    this->CSVButton->setText("CSV");                    // !!! OR QComboBox (to choose between CSV or HTML)
    this->HTMLButton = new QPushButton();
    this->HTMLButton->setFont(fileTypeFont);
    this->HTMLButton->setText("HTML");
    buttonsLayout->addWidget(this->CSVButton, 0, 0);
    buttonsLayout->addWidget(this->HTMLButton, 0, 1);

    fileTypeLayout->addLayout(buttonsLayout);

    centralWidget->setLayout(fileTypeLayout);
    this->setCentralWidget(centralWidget);

//    QFont fileTypeFont("Helvetica", 10, QFont::Bold);
//
//    this->setWindowTitle("Trench coats shop");
//
//    QVBoxLayout* fileTypeLayout = new QVBoxLayout{ this };
//
//    QLabel* userOrAdminLabel = new QLabel{"Choose the type of file:"};
//    userOrAdminLabel->setFont(fileTypeFont);
//    userOrAdminLabel->show();
//
//    fileTypeLayout->addWidget(userOrAdminLabel);                          // for  QWidget
//
//    this->CSVButton = new QPushButton{"CSV"};
//    this->CSVButton->setFont(fileTypeFont);
//    this->HTMLButton = new QPushButton{"HTML"};
//    this->HTMLButton->setFont(fileTypeFont);
//
//    QGridLayout* buttonsLayout = new QGridLayout{};
//    buttonsLayout->addWidget(this->CSVButton, 0, 0);
//    buttonsLayout->addWidget(this->HTMLButton, 0, 1);
//
//    fileTypeLayout->addLayout(buttonsLayout);
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->CSVButton, &QPushButton::clicked, this, &GUI::init_CSV);
    QObject::connect(this->HTMLButton, &QPushButton::clicked, this, &GUI::init_HTML);
}

void GUI::init_CSV() {
    this->asp = new CSVShoppingBasket{};
    this->close();
    UserOrAdmin* uoa = new UserOrAdmin(this->service, this->validator, this->userService, this->asp);
    uoa->show();
}

void GUI::init_HTML() {
    this->asp = new HTMLShoppingBasket{};
    this->close();
    UserOrAdmin* uoa = new UserOrAdmin(this->service, this->validator, this->userService, this->asp);
    uoa->show();
}

GUI::~GUI() = default;



UserOrAdmin::UserOrAdmin(Service &service, Validator &validator, UserService &userService, AbstractShoppingBasket *asp, QWidget* parent): QDialog{parent}, service{service}, validator{validator}, userService{userService}, asp{asp} {
    this->init_mode();
    this->connectSignalsAndSlots();
}

void UserOrAdmin::init_mode() {
    QFont userOrAdminFont("Helvetica", 10, QFont::Bold);

    this->setWindowTitle("Trench coats shop");

    QVBoxLayout* fileTypeLayout = new QVBoxLayout{ this };

    QLabel* userOrAdminLabel = new QLabel{"Choose the mode:"};
    userOrAdminLabel->setFont(userOrAdminFont);
    userOrAdminLabel->show();

    fileTypeLayout->addWidget(userOrAdminLabel);

    this->AdminButton = new QPushButton{"Admin mode"};
    this->AdminButton->setFont(userOrAdminFont);
    this->UserButton = new QPushButton{"User mode"};
    this->UserButton->setFont(userOrAdminFont);

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->AdminButton, 0, 0);
    buttonsLayout->addWidget(this->UserButton, 0, 1);

    fileTypeLayout->addLayout(buttonsLayout);
}

void UserOrAdmin::connectSignalsAndSlots() {
    QObject::connect(this->AdminButton, &QPushButton::clicked, this, &UserOrAdmin::init_adminMode);
    QObject::connect(this->UserButton, &QPushButton::clicked, this, &UserOrAdmin::init_userMode);
}

void UserOrAdmin::init_adminMode() {
    this->close();
    AdminMode* adminMode = new AdminMode(this->service, this->validator);
    adminMode->show();
}

void UserOrAdmin::init_userMode() {
    this->close();
    UserMode* userMode = new UserMode(this->userService, this->asp);
    userMode->show();
}

UserOrAdmin::~UserOrAdmin() = default;



AdminMode::AdminMode(Service &service, Validator &validator, QWidget *parent): QDialog{parent}, service{service}, validator{validator} {
    this->init_admin();
    this->populate_list();
    this->connectSignalsAndSlots();
}

void AdminMode::init_admin() {
    QFont adminFont("Helvetica", 10, QFont::Bold);

    this->setWindowTitle("Trench coats shop");

//    this->trenchCoatTableWidget = new QTableWidget{};
//    this->trenchCoatTableWidget->setFont(adminFont);
//    this->trenchCoatTableWidget->setColumnCount(5);

    this->trenchCoatListWidget = new QListWidget{};
    this->trenchCoatListWidget->setFont(adminFont);
    this->sizeLineEdit = new QLineEdit{};
    this->sizeLineEdit->setFont(adminFont);
    this->colorLineEdit = new QLineEdit{};
    this->colorLineEdit->setFont(adminFont);
    this->priceLineEdit = new QLineEdit{};
    this->priceLineEdit->setFont(adminFont);
    this->quantityLineEdit = new QLineEdit{};
    this->quantityLineEdit->setFont(adminFont);
    this->photographLineEdit = new QLineEdit{};
    this->photographLineEdit->setFont(adminFont);
    this->addButton = new QPushButton{"Add coat"};
    this->addButton->setFont(adminFont);
    this->deleteButton = new QPushButton{"Delete coat"};
    this->deleteButton->setFont(adminFont);
    this->updatePriceButton = new QPushButton{"Update price"};
    this->updatePriceButton->setFont(adminFont);
    this->updateQuantityButton = new QPushButton{"Update quantity"};
    this->updateQuantityButton->setFont(adminFont);
    this->graphicalReprButton = new QPushButton{"Graphical representation"};
    this->graphicalReprButton->setFont(adminFont);

    QVBoxLayout* mainLayout = new QVBoxLayout{this};
    mainLayout->addWidget(this->trenchCoatListWidget);
//    mainLayout->addWidget(this->trenchCoatTableWidget);

    QFormLayout* trenchCoatDetailsLayout = new QFormLayout{};
    trenchCoatDetailsLayout->addRow("Size", this->sizeLineEdit);
    trenchCoatDetailsLayout->addRow("Color", this->colorLineEdit);
    trenchCoatDetailsLayout->addRow("Price", this->priceLineEdit);
    trenchCoatDetailsLayout->addRow("Quantity", this->quantityLineEdit);
    trenchCoatDetailsLayout->addRow("Photograph", this->photographLineEdit);

    mainLayout->addLayout(trenchCoatDetailsLayout);

    QGridLayout* buttonsLayout = new QGridLayout{};
    buttonsLayout->addWidget(this->addButton, 0, 0);
    buttonsLayout->addWidget(this->deleteButton, 0, 1);
    buttonsLayout->addWidget(this->updatePriceButton, 1, 0);
    buttonsLayout->addWidget(this->updateQuantityButton, 1, 1);
    buttonsLayout->addWidget(this->graphicalReprButton, 2, 0, 1, 2);

    mainLayout->addLayout(buttonsLayout);
}

void AdminMode::populate_list() {
    this->trenchCoatListWidget->clear();

//    this->trenchCoatTableWidget->clear();
//    QStringList header = {"Size", "Color", "Price", "Quantity", "Photograph"};
//    header << "aia";
//    this->trenchCoatTableWidget->setHorizontalHeaderLabels(header);

    vector<trenchCoat> data = this->service.getRepository().getDynArr();

//    this->trenchCoatTableWidget->setRowCount(data.size() + 1);

//    int index = 0;

    for (auto & element : data) {
        char string[100];
        element.to_string(string);
        this->trenchCoatListWidget->addItem(string);  // QString::fromStdString() if it was string, not char
//        this->trenchCoatTableWidget->setItem(index, 0, new QTableWidgetItem(QString::fromStdString(element.getSize())));
//        this->trenchCoatTableWidget->setItem(index, 1, new QTableWidgetItem(QString::fromStdString(element.getColor())));
//        this->trenchCoatTableWidget->setItem(index, 2, new QTableWidgetItem(QString::number(element.getPrice())));
//        this->trenchCoatTableWidget->setItem(index, 3, new QTableWidgetItem(QString::number(element.getQuantity())));
//        this->trenchCoatTableWidget->setItem(index, 4, new QTableWidgetItem(QString::fromStdString(element.getPhotograph())));
//        index++;
    }
}

void AdminMode::connectSignalsAndSlots() {
    QObject::connect(this->trenchCoatListWidget, &QListWidget::itemSelectionChanged, [this]() {           //cellClicked for table
        int selectedIndex = this->get_selected_index();

        if (selectedIndex == -1)
            return;

        trenchCoat coat = this->service.getRepository().getDynArr()[selectedIndex];

        this->sizeLineEdit->setText(QString::fromStdString(coat.getSize()));
        this->colorLineEdit->setText(QString::fromStdString(coat.getColor()));
        this->priceLineEdit->setText(QString::number(coat.getPrice()));
        this->quantityLineEdit->setText(QString::number(coat.getQuantity()));
        this->photographLineEdit->setText(QString::fromStdString(coat.getPhotograph()));
    });

    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminMode::add_coat);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminMode::delete_coat);
    QObject::connect(this->updatePriceButton, &QPushButton::clicked, this, &AdminMode::update_price);
    QObject::connect(this->updateQuantityButton, &QPushButton::clicked, this, &AdminMode::update_quantity);
    QObject::connect(this->graphicalReprButton, &QPushButton::clicked, this, &AdminMode::graphical_representation);
}

int AdminMode::get_selected_index() const {
    QModelIndexList selectedIndexes = this->trenchCoatListWidget->selectionModel()->selectedIndexes();

    if (selectedIndexes.empty()) {
        this->sizeLineEdit->clear();
        this->colorLineEdit->clear();
        this->priceLineEdit->clear();
        this->quantityLineEdit->clear();
        this->photographLineEdit->clear();
        return -1;
    }

    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void AdminMode::add_coat() {
    string size, color, price, quantity, photograph;

    size = this->sizeLineEdit->text().toStdString();
    color = this->colorLineEdit->text().toStdString();
    price = this->priceLineEdit->text().toStdString();
    quantity = this->quantityLineEdit->text().toStdString();
    photograph = this->photographLineEdit->text().toStdString();

    try{
        Validator::validate_price_or_quantity(price);
        this->validator.validate_price_or_quantity(quantity);
        this->validator.validate_size(size);
        this->validator.validate_color(color);
        this->validator.validate_photograph(photograph);
        int newPrice = stoi(price);
        int newQuantity = stoi(quantity);

        this->service.add_service(size, color, newPrice, newQuantity, photograph);

        this->populate_list();

        int lastElement = this->service.getRepository().getDynArr().size() - 1;
        this->trenchCoatListWidget->setCurrentRow(lastElement);
    }
    catch (const CustomException& except) {
        QMessageBox::critical(this, "Error", "Error on add!");
    }
}

void AdminMode::delete_coat() {
    int selectedIndex = this->get_selected_index();

    if (selectedIndex == -1) {
        QMessageBox::critical(this, "Error", "No coat selected!");
        return;
    }

    trenchCoat coat = this->service.getRepository().getDynArr()[selectedIndex];

    string size, color, photograph;
    size = coat.getSize();
    color = coat.getColor();
    photograph = coat.getPhotograph();

    try{
        this->validator.validate_size(size);
        this->validator.validate_color(color);
        this->validator.validate_photograph(photograph);
        this->service.delete_service(size, color, photograph);

        this->populate_list();
    }
    catch (const CustomException& except) {
        QMessageBox::critical(this, "Error", "Error on delete!");
    }
}

void AdminMode::update_price() {
    string size, color, price, photograph;

    int selectedIndex = this->get_selected_index();

    if (selectedIndex == -1) {
        QMessageBox::critical(this, "Error", "No coat selected!");
        return;
    }

    trenchCoat coat = this->service.getRepository().getDynArr()[selectedIndex];

    size = this->sizeLineEdit->text().toStdString();
    color = this->colorLineEdit->text().toStdString();
    price = this->priceLineEdit->text().toStdString();
    photograph = this->photographLineEdit->text().toStdString();

    if (stoi(price) == coat.getPrice()) {
        QMessageBox::critical(this, "Error", "The price needs to change in order to be updated!");
        return;
    }

    try {
        Validator::validate_price_or_quantity(price);
        this->validator.validate_size(size);
        this->validator.validate_color(color);
        this->validator.validate_photograph(photograph);
        int newPrice = stoi(price);
        this->service.update_price_service(size, color, newPrice, photograph);

        this->populate_list();
    }
    catch (const CustomException& except) {
        QMessageBox::critical(this, "Error", "Error on update price!");
    }
}

void AdminMode::update_quantity() {
    string size, color, quantity, photograph;

    int selectedIndex = this->get_selected_index();

    if (selectedIndex == -1) {
        QMessageBox::critical(this, "Error", "No coat selected!");
        return;
    }

    trenchCoat coat = this->service.getRepository().getDynArr()[selectedIndex];

    size = this->sizeLineEdit->text().toStdString();
    color = this->colorLineEdit->text().toStdString();
    quantity = this->quantityLineEdit->text().toStdString();
    photograph = this->photographLineEdit->text().toStdString();

    if (stoi(quantity) == coat.getQuantity()) {
        QMessageBox::critical(this, "Error", "The quantity needs to change in order to be updated!");
        return;
    }

    try {
        Validator::validate_price_or_quantity(quantity);
        this->validator.validate_size(size);
        this->validator.validate_color(color);
        this->validator.validate_photograph(photograph);
        int newQuantity = stoi(quantity);
        this->service.update_quantity_service(size, color, newQuantity, photograph);

        this->populate_list();
    }
    catch (const CustomException& except) {
        QMessageBox::critical(this, "Error", "Error on update quantity!");
    }
}

void AdminMode::graphical_representation() {
    QtCharts::QBarSet *barXS = new QtCharts::QBarSet("XS");
    QtCharts::QBarSet *barS = new QtCharts::QBarSet("S");
    QtCharts::QBarSet *barM = new QtCharts::QBarSet("M");
    QtCharts::QBarSet *barL = new QtCharts::QBarSet("L");
    QtCharts::QBarSet *barXL = new QtCharts::QBarSet("XL");
    QtCharts::QBarSet *barXXL = new QtCharts::QBarSet("XXL");

    int ctxs = 0, cts = 0, ctm = 0, ctl = 0, ctxl = 0, ctxxl = 0;
    vector<trenchCoat> data = this->service.getRepository().getDynArr();

    for (auto & element : data) {
        if (element.getSize() == "XS")
            ctxs += element.getQuantity();
        if (element.getSize() == "S")
            cts += element.getQuantity();
        if (element.getSize() == "M")
            ctm += element.getQuantity();
        if (element.getSize() == "L")
            ctl += element.getQuantity();
        if (element.getSize() == "XL")
            ctxl += element.getQuantity();
        if (element.getSize() == "XXL")
            ctxxl += element.getQuantity();
    }

    *barXS << ctxs;
    *barS << 0 << cts;
    *barM << 0 << 0 << ctm;
    *barL << 0 << 0 << 0 << ctl;
    *barXL << 0 << 0 << 0 << 0 << ctxl;
    *barXXL << 0 << 0 << 0 << 0 << 0 << ctxxl;

    QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    series->append(barXS);
    series->append(barS);
    series->append(barM);
    series->append(barL);
    series->append(barXL);
    series->append(barXXL);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle("Graphical representation");
    chart->setAnimationOptions(QtCharts::QChart::SeriesAnimations);

    QStringList sizes;
    sizes << "XS" << "S" << "M" << "L" << "XL" << "XXL";

    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(sizes);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    axisY->setRange(0, 100);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


//    QDialog* window = new QDialog();    //    QWidget* window = new QWidget();
//    window->setParent(nullptr);        //     window->setParent(nullptr);
//    window->show();                    //     window->show();

    QMainWindow* window = new QMainWindow();
    window->setCentralWidget(chartView);
    window->resize(600, 600);
    window->show();
}

AdminMode::~AdminMode() = default;



UserMode::UserMode(UserService &userService, AbstractShoppingBasket *asp, QWidget* parent): QDialog{parent}, userService{userService}, asp{asp} {
    this->init_user();
    this->connectSignalsAndSlots();
}

void UserMode::init_user() {
    QFont userFont("Helvetica", 10, QFont::Bold);

    this->setWindowTitle("Trench coats shop");

    this->trenchCoatSizeListWidget = new QListWidget{};
    this->trenchCoatSizeListWidget->setFont(userFont);
    this->shoppingBasketListWidget = new QListWidget{};
    this->shoppingBasketListWidget->setFont(userFont);
    this->priceButton = new QPushButton{"Total price"};
    this->priceButton->setFont(userFont);
    this->applicationButton = new QPushButton{"Open CSV or HTML"};
    this->applicationButton->setFont(userFont);
    this->seeCoatsButton = new QPushButton{"See coats of the given size"};
    this->seeCoatsButton->setFont(userFont);
    this->sizeLineEdit = new QLineEdit{};
    this->sizeLineEdit->setFont(userFont);

    QFormLayout* sizeLayout = new QFormLayout{};
    sizeLayout->addRow("Size", this->sizeLineEdit);

    QGridLayout* mainLayout = new QGridLayout{this};
    mainLayout->addWidget(this->trenchCoatSizeListWidget, 0, 0);
    mainLayout->addWidget(this->shoppingBasketListWidget, 0, 1);
    mainLayout->addWidget(this->priceButton, 3, 0);
    mainLayout->addWidget(this->seeCoatsButton, 2, 0, 1, 2);
    mainLayout->addWidget(this->applicationButton, 3, 1);
    mainLayout->addLayout(sizeLayout, 1, 0);

    QLabel* label = new QLabel();
    label->setFont(userFont);
    label->setText("Shopping basket: ↑");
    label->show();
    mainLayout->addWidget(label, 1, 1);
}

void UserMode::populate_list() {
    string size;

    this->trenchCoatSizeListWidget->clear();

    size = this->sizeLineEdit->text().toStdString();
    if (size == "XXS" || size == "XS" || size == "S" || size == "M" || size == "L" || size == "XL" || size == "XXL" || size.empty()) {
            this->userService.available_size_coats(size);
            if (this->userService.getAvailableSizeCoats().empty())
                QMessageBox::critical(this, "Error", "This size is not in the stock anymore! Try another one.");
    }
    else
        QMessageBox::critical(this, "Error", "Invalid size! Try another one.");

    vector<trenchCoat> data = this->userService.getAvailableSizeCoats();

    for (auto & element : data) {
        char string[100];
        element.to_string(string);
        this->trenchCoatSizeListWidget->addItem(string);
    }
}

void UserMode::connectSignalsAndSlots() {
    QObject::connect(this->seeCoatsButton, &QPushButton::clicked, this, &UserMode::populate_list);
    QObject::connect(this->trenchCoatSizeListWidget, &QListWidget::itemSelectionChanged, this, &UserMode::add_to_basket);
    QObject::connect(this->priceButton, &QPushButton::clicked, this, &UserMode::show_total_price);
    QObject::connect(this->applicationButton, &QPushButton::clicked, this, &UserMode::see_basket_application);
}

int UserMode::get_selected_index() const {
    QModelIndexList selectedIndexes = this->trenchCoatSizeListWidget->selectionModel()->selectedIndexes();

    if (selectedIndexes.empty()) {
        return -1;
    }

    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void UserMode::add_to_basket() {
    int selectedIndex = this->get_selected_index();

    if (selectedIndex == -1)
            return;

    trenchCoat coat = this->userService.getAvailableSizeCoats()[selectedIndex];

    this->shoppingBasketListWidget->addItem(QString::fromStdString(coat.getSize() + " - " + coat.getColor() + " - " + coat.getPhotograph()));

    int totalPrice;
    totalPrice = *this->userService.getTotalPrice();
    totalPrice += coat.getPrice();
    this->userService.setTotalPrice(totalPrice);
    this->userService.update_basket(selectedIndex);

    if (this->userService.getAvailableSizeCoats().at(selectedIndex).getQuantity() == 0)
        this->userService.delete_quantity_zero(selectedIndex);

    if (this->userService.getAvailableSizeCoats().empty())
        QMessageBox::critical(this, "Error", "There are no more coats of this type in the store!");

    this->populate_list();
}

void UserMode::show_total_price() {
    int totalPrice = *this->userService.getTotalPrice();
    QMessageBox msgBox;
    msgBox.setText("The total price is " + QString::number(totalPrice));
    msgBox.exec();
}

void UserMode::see_basket_application() {
    std::vector<trenchCoat> basket = this->userService.getBasket();
    this->asp->setData(basket);
    this->asp->write();
    this->asp->open();
}

UserMode::~UserMode() = default;
