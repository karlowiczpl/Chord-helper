#ifndef LEGEND_H
#define LEGEND_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Legend : public QWidget
{
Q_OBJECT

public:
    Legend(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    struct LegendItem {
        QColor color;
        QString description;
    };
    QVector<LegendItem> items;
};

#endif // LEGEND_H
