#ifndef CIRCULAR_LAYOUT_H
#define CIRCULAR_LAYOUT_H

#include <QLayout>
#include <QWidget>
#include <QList>
#include <QtMath>

class CircularLayout : public QLayout {
public:
    explicit CircularLayout(QWidget *parent = nullptr);

    void addItem(QLayoutItem *item) override;
    [[nodiscard]] QSize sizeHint() const override;
    void setGeometry(const QRect &rect) override;

    [[nodiscard]] int count() const override;
    [[nodiscard]] QLayoutItem* itemAt(int index) const override;
    QLayoutItem* takeAt(int index) override;

private:
    QList<QLayoutItem *> items;
};

#endif // CIRCULAR_LAYOUT_H
