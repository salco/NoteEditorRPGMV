#include "includes/mainwindow.h"
#include "ui_mainwindow.h"

#include <cstring>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//        fileSystemModel.setOption(QFileSystemModel::DontUseCustomDirectoryIcons);
//        fileSystemModel.setOption(QFileSystemModel::DontWatchForChanges);
    fileSystemModel.setNameFilters({"*.json"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTestText(std::string text)
{
    char *p = strrchr(text.c_str(), '\\');
    if(p) p[0] = 0;

    ui->textEdit->setPlainText(text.c_str());

    fileSystemModel.setRootPath((ui->textEdit->toPlainText()));
    ui->treeView->setModel(&fileSystemModel);
    ui->treeView->setRootIndex(fileSystemModel.index((ui->textEdit->toPlainText())));
}
