//
// Created by paula on 6/20/2021.
//

#ifndef CODE_REVISION_PROGRAMMERWINDOW_H
#define CODE_REVISION_PROGRAMMERWINDOW_H

#include "../Observer/Observer.h"
#include "../TableModel/TableModel.h"
#include "../RepoProgrammers/RepoProgrammers.h"
#include "../RepoFiles/Files.h"
#include <QWidget>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSortFilterProxyModel>
#include <QLabel>
#include <QMessageBox>


class ProgrammerWindow : public QWidget, public Observer {
private:
    Programmer& p;
    Files& files;

    QLineEdit* fileNameLineEdit;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QPushButton* addFileButton, *reviseFileButton;
    QLabel* nrReviewedFilesLabel, *nrLeftFilesLabel;
    TableModel* tableModel;
    QTableView* sourceFilesTableView;
    QSortFilterProxyModel* filterModel;

public:
    ProgrammerWindow(Files& files, Programmer& p); // third parameter QWidget*parent=Q_NULLPTR, not really necessary

    void update() override;

    void notifyModel();

    int getSelectedIndex();

    void checkIfReviseAvailable();

    void revise();

    void connectSignals();

    void initGUI();

    void addSourceFile();

    ~ProgrammerWindow() override;
};


#endif //CODE_REVISION_PROGRAMMERWINDOW_H
