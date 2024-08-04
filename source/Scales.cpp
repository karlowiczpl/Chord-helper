#include "Scales.h"
#include "data/scaleData.h"
#include <utility>

Scales::Scales(const QString& type, const QString& notes)
{
    getScalePtr(type);
    int number = getNumberFromNote(notes);
    size = selectedScale.size;

    for (int i = 0; i < size; i++) {
        note.push_back(getNote(number));
        number += selectedScale.distances[i];
    }

    QString name;
    for (int i = 0; i < size; i++) {
        switch (selectedScale.chordTypes[i]) {
            case major: name = "Maj"; break;
            case minor: name = "Min"; break;
            case diminished: name = "Dim"; break;
            case increased: name = "Inc"; break;
        }
        chordNames.push_back(name);
    }

    for (int j = 0; j < size; j++) {
        int x = 0;
        std::vector<QString> chord;
        chord.push_back(note[j]);
        for (int i = 0; i < 2; i++) {
            x += chordTemplate[selectedScale.chordTypes[j]][i];
            chord.push_back(getNote(getNumberFromNote(note[j]) + x));
        }
        chords.push_back(std::move(chord));
    }
}

void Scales::getScalePtr(const QString& name)
{
    for (int i = 0; i < 9; i++) {
        if (allClassicScales[i] == name) {
            selectedScale.chordTypes = templateChordTypes[i];
            selectedScale.name = name;
            selectedScale.distances = templateDistances[i];
            selectedScale.size = 7;
            selectedScale.colors = chordsColors[i];
            break;
        }
    }
}
int Scales::getNumberFromNote(const QString& note) {
    for (int i = 0; i < 12; i++) {
        if (allNotes[i] == note) {
            return i;
        }
    }
    return -1;
}
QString Scales::getNote(int number) {
    return allNotes[number % 12];
}

int *Scales::generateChordTable(int position)
{
    static int chordTable[12];

    for(int & i : chordTable)     i = 0;

    auto ch = chords[position];
    for(int j = 0; j < ch.size(); j++)
    {
        for(int i = 0; i < 12; i++)
        {
            if(notesMapper[i] == ch[j])
            {
                if(j == 0)      chordTable[i] = 2;
                else    chordTable[i] = 1;
            }
        }
    }
    return chordTable;
}

QColor Scales::getColor(int position) const {
    return selectedScale.colors[position];
}


