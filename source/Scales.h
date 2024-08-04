#ifndef AKORDY_SCALES_H
#define AKORDY_SCALES_H

#include <QString>
#include <QDebug>
#include <vector>
#include <QColor>

#include "data/scaleData.h"

class Scales
{
public:
    Scales(const QString& type, const QString& note);
    QString getChordName(int position);
    std::vector<QString> getAllNotes();
    [[nodiscard]] int getScaleSize() const;
    std::vector<QString> getChordNotes(int position);
    int* generateChordTable(int position);
    QColor getColor(int position) const;

private:
    typedef struct {
        QString name;
        int* distances;
        chordsType* chordTypes;
        int size;
        QColor* colors;
    } SCALE_T;
    SCALE_T selectedScale;

    std::vector<QString> note;
    std::vector<QString> chordNames;
    int size;
    std::vector<std::vector<QString>> chords;

    static int getNumberFromNote(const QString& note);
    static QString getNote(int number);
    void getScalePtr(const QString& name);
};

#endif // AKORDY_SCALES_H
