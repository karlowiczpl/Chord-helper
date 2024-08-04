#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QString>
#include <QDebug>

class Keyboard : public QWidget
{
Q_OBJECT

public:
    Keyboard();
    void changeDisplayNotes(int*);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int* clickedNotes;
};

#endif // KEYBOARD_H
