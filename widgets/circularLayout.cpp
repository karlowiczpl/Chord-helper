#include "circularLayout.h"

CircularLayout::CircularLayout(QWidget *parent) : QLayout(parent) {}

void CircularLayout::addItem(QLayoutItem *item) {
    items.append(item);
}

QSize CircularLayout::sizeHint() const {
    return {200, 200};
}
void CircularLayout::setGeometry(const QRect &rect) {
    QLayout::setGeometry(rect);

    int itemCount = items.count();
    if (itemCount == 0)
        return;

    QPoint center = rect.center();
    int radius = qMin(rect.width() / 2, rect.height()) / 2 - 20;

    double startAngle = 0.90 * M_PI;
    double endAngle = -0.68 * M_PI;

    double spacingFactor = 0.5;

    for (int i = 0; i < itemCount; ++i) {
        QLayoutItem *item = items.at(i);

        double angle = startAngle + (endAngle - startAngle) * i / (itemCount - 1) * spacingFactor;
        double x = center.x() + radius * qCos(angle) - (double)item->sizeHint().width() / 2;
        double y = center.y() + radius * qSin(angle) - (double)item->sizeHint().height() / 2;

        item->setGeometry(QRect(QPoint((int)x, (int)y - 50), item->sizeHint()));
    }
}
int CircularLayout::count() const {
    return items.count();
}

QLayoutItem* CircularLayout::itemAt(int index) const {
    return items.value(index);
}

QLayoutItem* CircularLayout::takeAt(int index) {
    if (index >= 0 && index < items.size())
        return items.takeAt(index);
    return nullptr;
}
