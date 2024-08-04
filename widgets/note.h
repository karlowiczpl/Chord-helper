#ifndef CHORDS_NOTE_H
#define CHORDS_NOTE_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QFont>
#include <QPainterPath>
#include <QMouseEvent>
#include <utility>

#include "mainwindow.h"
#include "keyboard.h"
#include "../source/Scales.h"

class Note : public QWidget {
Q_OBJECT

public:
    explicit Note(QString label , QString chord, int size ,QWidget* parent = nullptr);
    void setColor(const QColor& color);
    void setScales(Scales* scales);

    std::vector<QString> chordNotes;
    Keyboard* keyboard{};

    int position;
    bool isInsideCircle(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QString label;
    QColor color;
    QString chord;
    Scales* scales;

    int size;
    bool clicked;
};


#endif //CHORDS_NOTE_H
