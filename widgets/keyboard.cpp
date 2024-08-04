#include "keyboard.h"

Keyboard::Keyboard()
{
    static int clkNotes[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    clickedNotes = clkNotes;
    setFixedSize(1000, 100);
}
void Keyboard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int sideLength = 100;

    int x = 160;
    int y = (height() - sideLength) / 2;

    int distances[5] = {22 , 53 , 113 , 143 , 173};
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 7; i++)
        {
            if(clickedNotes[i] == 0)    painter.setBrush(Qt::white);
            else if(clickedNotes[i] == 2)   painter.setBrush(Qt::darkGreen);
            else    painter.setBrush(Qt::green);
            painter.setPen(Qt::NoPen);
            painter.drawRect(x + (i * 30) + (j * 210), y, 30, 100);

            painter.setPen(QPen(Qt::black , 2));
            painter.drawRect(x + (i * 30) + (j * 210), y , 30 , 100);
        }
        for(int i = 0; i < 5; i++)
        {
            if(clickedNotes[i + 7] == 0)    painter.setBrush(Qt::black);
            else if(clickedNotes[i + 7] == 2)   painter.setBrush(Qt::darkGreen);
            else    painter.setBrush(Qt::green);
            painter.drawRect(x + distances[i] + (j * 210) , y , 15 , 70);

            painter.setPen(QPen(Qt::black , 2));
            painter.drawRect(x + distances[i] + (j * 210), y , 15 , 70);
        }
    }
}
void Keyboard::changeDisplayNotes(int* notes)
{
    clickedNotes = notes;
    update();
}