#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::saveImage);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::encodeMsg);
}

void MainWindow::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open Image", "", "Допустимые форматы (*.png)");
    image.load(fileName);
    image.convertTo(QImage::Format_ARGB32);
    if (image.load(fileName)) {
        ui->label->setText("Изображение успешно загружено");
    } else {
        ui->label->setText("Изображение не загружено");
    }
}

void MainWindow::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Image", "", "Допустимые форматы (*.png)");
    image.save(fileName);
    if (image.save(fileName)) {
        ui->label->setText("Изображение успешно сохранено");
    } else {
        ui->label->setText("Изображение не сохранено");
    }
}

void MainWindow::encodeMsg()
{
    QString text = ui->plainTextEdit->toPlainText();
    QByteArray byteText = text.toUtf8().toHex();
    double imageSzie = QImage(image).width() * QImage(image).height() * 3;
    QString s; s.setNum(imageSzie);
    if (text.size() + byteText.size() + s.size() > imageSzie) ui->label->setText("Ошибка. Не достаточно места!");
    //ui->plainTextEdit->insertPlainText(text + byteText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

