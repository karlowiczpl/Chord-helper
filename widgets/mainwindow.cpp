#include "mainwindow.h"
#include "note.h"
#include "circularLayout.h"
#include "keyboard.h"
#include "legend.h"

MainWindow::MainWindow()
{
    generateUi();
    QPalette palette1 = palette();
    palette1.setColor(QPalette::Window , QColor(0x90d1e7));
    setPalette(palette1);

    for(const auto & allNote : allNotes) noteBox->addItem(allNote);
    for(const auto & allClassicScale : allClassicScales) scalesBox->addItem(allClassicScale);

    connect(scalesBox , &QComboBox::currentTextChanged , this , &MainWindow::removeAllNotes);
    connect(noteBox , &QComboBox::currentTextChanged , this , &MainWindow::removeAllNotes);

    removeAllNotes();
}
void MainWindow::generateUi()
{
    show();
    resize(1200, 800);

    auto* centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    mainLayout = new QGridLayout;
    centralWidget->setLayout(mainLayout);
    comboBoxLayout = new QHBoxLayout;

    auto* legend = new Legend(centralWidget);
    legend->setGeometry(50, 50, 300, 200);

    auto* spacerItem = new QSpacerItem(10 , 0);
    mainLayout->addItem(spacerItem , 2 , 0 , 1 ,1);
    mainLayout->addLayout(comboBoxLayout , 3 , 0);
    auto* spaceItem = new QSpacerItem(10 , 0);
    mainLayout->addItem(spaceItem , 1 , 0 , 1 ,1);

    scalesBox = new QComboBox;
    noteBox = new QComboBox;

    comboBoxLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
    comboBoxLayout->addWidget(scalesBox);
    comboBoxLayout->addWidget(noteBox);
    comboBoxLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    keyboard = new Keyboard;

    mainLayout->addWidget(keyboard);
    notesLayout = new CircularLayout;
    mainLayout->addLayout(notesLayout , 3 , 0);
}

void MainWindow::removeAllNotes()
{
    while (QLayoutItem* item = notesLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        delete item;
    }
    auto* scales = new Scales(scalesBox->currentText() , noteBox->currentText());

    std::vector<QString> scalesName = scales->getAllNotes();
        for(int i = 0; i < scales->getScaleSize(); i++)
        {
            Note* note = new Note(scalesName[i] ,scales->getChordName(i) , sizes[i]);

            note->setColor(scales->getColor(i));
            note->keyboard = keyboard;
            note->setScales(scales);
            note->position = i;

            notesLayout->addWidget(note);
            scales->generateChordTable(1);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int x = (width() - 700) / 2;
    int y = (height() - 700) / 2;

    painter.setBrush(QColor(0x170543));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(x, y, 700, 700);

    QFont titleFont = painter.font();
    titleFont.setBold(true);
    titleFont.setPointSize(135);
    painter.setFont(titleFont);

    QRect titleFontRect(0, -30, width(), height());

    painter.setPen(QColor(0x170543).lighter(150));
    painter.drawText(titleFontRect, Qt::AlignCenter, "Chords");

    QString styleSheet = R"(
        QComboBox {
            background: transparent;
            border: 2px solid #0000FF;  /* Blue border color and width */
            border-radius: 10px;  /* Rounded corners */
            font-size: 20px;  /* Font size */
            color: white;  /* Font color */
            padding: 5px;
        }
        QComboBox::drop-down {
            border: 2px solid #0000FF;  /* Blue border color and width for the drop-down */
            border-radius: 10px;  /* Rounded corners */
            background: transparent;  /* Background for the drop-down arrow */
        }
        QComboBox QAbstractItemView {
            background: rgba(0, 0, 0, 150);  /* Semi-transparent background for the drop-down menu */
            color: white;  /* Font color in the drop-down menu */
            selection-background-color: #404040;  /* Background color of selected item */
            selection-color: white;  /* Font color of selected item */
            border: 2px solid #0000FF;  /* Blue border color and width for the drop-down menu */
            border-radius: 10px;  /* Rounded corners */
        }
    )";

    scalesBox->setStyleSheet(styleSheet);
    noteBox->setStyleSheet(styleSheet);
}

