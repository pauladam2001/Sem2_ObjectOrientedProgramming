//
// Created by paul on 5/3/2021.
//

#ifndef A89_PAULADAM2001_GUI_H
#define A89_PAULADAM2001_GUI_H

#include "service.h"
#include "validators.h"
#include "userService.h"
#include "AbstractBasket.h"
#include "../QtViewModel/tableModel.h"

#include <qwidget.h>
#include <QMainWindow>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <QDialog>
#include <QTableWidget>
#include "QShortcut"
#include <QTableView>


class GUI : public QMainWindow {            // SAU QWidget la toate in loc de QMainWindow si QDialog   (QWidget daca avem o singura fereastra)
private:

    Service& service;
    Validator& validator;
    UserService& userService;
    AbstractShoppingBasket* asp{};

    QPushButton *CSVButton{}, *HTMLButton{};

public:

    GUI(Service& service, Validator& validator, UserService& userService, QWidget *parent = nullptr);

    ~GUI();

private:

    void init_fileType();

    void connectSignalsAndSlots();

    void init_CSV();

    void init_HTML();
};



class UserOrAdmin : public QDialog {
private:

    Service& service;
    Validator& validator;
    UserService& userService;
    AbstractShoppingBasket* asp{};

    QPushButton *AdminButton{}, *UserButton{};

public:

    UserOrAdmin(Service& service, Validator& validator, UserService& userService, AbstractShoppingBasket* asp, QWidget* parent = nullptr);

    ~UserOrAdmin();

private:

    void init_mode();

    void connectSignalsAndSlots();

    void init_adminMode();

    void init_userMode();
};



class AdminMode : public QDialog {
private:

    Service& service;
    Validator& validator;

    QListWidget* trenchCoatListWidget{};
//    QTableWidget* trenchCoatTableWidget{};
    QLineEdit* sizeLineEdit{}, *colorLineEdit{}, *priceLineEdit{}, *quantityLineEdit{}, *photographLineEdit{};
    QPushButton* addButton{}, *deleteButton{}, *updatePriceButton{}, *updateQuantityButton{}, *graphicalReprButton{}, *undoButton{}, *redoButton{};
    QShortcut *undoShortcut{}, *redoShortcut{};

public:

    AdminMode(Service& service, Validator& validator, QWidget* parent = nullptr);

    ~AdminMode();

private:

    void init_admin();

    void populate_list();

    void connectSignalsAndSlots();

    int get_selected_index() const;

    void add_coat();

    void delete_coat();

    void update_price();

    void update_quantity();

    void graphical_representation();

    void undo();

    void redo();
};



class UserMode : public QDialog {
private:

    UserService& userService;
    AbstractShoppingBasket* asp{};

    QListWidget* trenchCoatSizeListWidget{}, *shoppingBasketListWidget{};
    QLineEdit* sizeLineEdit{};
    QPushButton* priceButton{}, *applicationButton{}, *seeCoatsButton{};

    QPushButton* tableButton{};
    QTableView* basketTableView{};
    CustomTableModel* tableModel;

public:

    UserMode(UserService& userService, AbstractShoppingBasket* asp, QWidget* parent = nullptr);

    ~UserMode();

private:

    void init_user();

    void populate_list();

    void connectSignalsAndSlots();

    int get_selected_index() const;

    void add_to_basket();

    void show_total_price();

    void see_basket_application();

    void open_tableView();

    void update_tabel_in_real_time();
};


#endif //A89_PAULADAM2001_GUI_H
