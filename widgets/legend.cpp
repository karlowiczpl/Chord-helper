#include "legend.h"

Legend::Legend(QWidget* parent)
        : QWidget(parent)
{
    setFixedSize(300, 250);

    items = {
            {QColor(0xff87a5), "Tonika"},
            {QColor(0x69ddea), "Subdominanta"},
            {QColor(0xfbd4a1), "Medianta"},
            {QColor(0x4fcee9), "Dominanta"},
            {QColor(0xa1fbc3), "Submedianta"},
            {QColor(0xb6a3dc), "Super Tonika"},
            {QColor(0xeabf69), "Zmniejszony"},
    };
}

void Legend::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QFont baseFont = painter.font();
    baseFont.setPointSize(18);
    painter.setFont(baseFont);

    int circleDiameter = 20;
    int spacing = 30;
    int x = 20;
    int y = 30;

    for (const auto& item : items) {
        painter.setBrush(item.color);
        painter.setPen(Qt::NoPen);
        painter.drawEllipse(x, y, circleDiameter, circleDiameter);

        painter.setPen(QPen(Qt::black , 3));
        painter.drawEllipse(x, y, circleDiameter, circleDiameter);

        painter.setPen(Qt::black);
        painter.drawText(x + circleDiameter + 10, y + circleDiameter / 2 + 10, item.description);

        y += spacing;
    }
}
