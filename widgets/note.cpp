#include <QDebug>
#include "note.h"

Note::Note(QString label, QString chord, int size, QWidget* parent) :
        color(0x6be0f5), QWidget(parent), label(std::move(label)), chord(std::move(chord)), size(size) , clicked(true)
{
    setFixedSize(size, size);
}

void Note::setColor(const QColor &col)
{
    color = col;
    update();
}

void Note::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    double d1 = qMin(width(), height()) * 0.40;
    int diameter = static_cast<int>(d1);

    int x = (width() - diameter) / 2;
    int y = (height() - diameter) / 2;

    QColor shadowColor = color.darker(200);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(clicked)
    {
        painter.setBrush(QBrush(Qt::white));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(x - (size / 30), y - (size / 30), diameter + (size / 15), diameter + (size / 15));
    }

    if(clicked)
    {
        painter.setBrush(QBrush(shadowColor));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(x - (size / 37), y, diameter + (size / 19), diameter + (size / 25));
    }

    if(clicked)
    {
        painter.setBrush(QBrush(color));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(x, y, diameter, diameter);
    }else
    {
        painter.setBrush(QBrush(color));
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(x - (size / 30), y - (size / 30), diameter + (size / 15), diameter + (size / 15));

        painter.setPen(QPen(color.darker(200) , 5));
        painter.drawEllipse(x - (size / 30), y - (size / 30), diameter + (size / 15), diameter + (size / 15));
    }

    QFont font1 = painter.font();
    font1.setBold(true);
    font1.setPointSize((size / 6));
    painter.setFont(font1);
    painter.setPen(Qt::black);

    QRect labelRect = QRect(0, 0, width(), height());
    painter.drawText(labelRect, Qt::AlignCenter, label);

    painter.setPen(Qt::white);
    font1.setPointSize((size / 10));
    painter.setFont(font1);
    QRect chordRect = QRect(0, (size / 3), width(), height());
    painter.drawText(chordRect, Qt::AlignCenter, chord);
}

void Note::mousePressEvent(QMouseEvent *event)
{
    if (isInsideCircle(event->x(), event->y())) {
        qDebug() << "Note clicked: " << label;
        if (keyboard && scales) {
            keyboard->changeDisplayNotes(scales->generateChordTable(position));
            clicked = false;
            update();
        }
    } else {
        QWidget::mousePressEvent(event);
    }

}

bool Note::isInsideCircle(int x, int y)
{
    int centerX = width() / 2;
    int centerY = height() / 2;
    int radius = qMin(width(), height()) * 0.40;

    int dx = x - centerX;
    int dy = y - centerY;

    return (dx * dx + dy * dy) <= (radius * radius);
}

void Note::setScales(Scales* scale)
{
    scales = scale;
}

void Note::mouseReleaseEvent(QMouseEvent *event) {
    clicked = true;
    update();
}

