#ifndef SCALEDATA_H
#define SCALEDATA_H

#include <QString>
#include <QColor>

extern const QString allNotes[12];
extern const QString allClassicScales[9];

enum chordsType { major, minor, diminished, increased };

extern chordsType templateChordTypes[9][7];
extern int templateDistances[9][7];
extern int chordTemplate[4][2];
extern QString notesMapper[12];
extern QColor chordsColors[9][7];

#endif // SCALEDATA_H
