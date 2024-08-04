#ifndef CHORD_MAIN_WINDOW_H
#define CHORD_MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPalette>
#include "note.h"
#include "../source/Scales.h"
#include <QPushButton>
#include <QLabel>
#include <QRect>

#include "circularLayout.h"
#include "keyboard.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow();

private:
    void generateUi();

private slots:
    void removeAllNotes();

public:
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QGridLayout* mainLayout{};
    QHBoxLayout* comboBoxLayout{};
    CircularLayout* notesLayout{};

    QComboBox* scalesBox{};
    QComboBox* noteBox{};
    Keyboard* keyboard{};

    int sizes[7] = {150 , 170 , 190 , 210 , 190 , 170 , 150};
    QColor colors[7] = {0xff87a5 , 0x4fcee9 , 0x69ddea , 0xfbd4a1 , 0x5ed8ed , 0x5ed8ed , 0xff87a5};
};


#endif //CHORD_MAIN_WINDOW_H
