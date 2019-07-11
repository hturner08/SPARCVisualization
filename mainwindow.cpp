#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "properties.h"
#include "graphdatamodifier.h"
#include "meshtalparser.h"
#include "randomfunctions.h"
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <QtDataVisualization>
#include <QStringList>
#include <QFileDialog>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtGui/QScreen>
#include <QtGui/QFontDatabase>
#include <QApplication>
#include <QScatterDataProxy>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new Q3DScatter();
    QWidget *container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(screenSize.width() / 2, screenSize.height() / 1.5));
    container->setMaximumSize(screenSize);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    container->setFocusPolicy(Qt::StrongFocus);

    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    widget->setLayout(hLayout);
    this->setCentralWidget(widget);

    widget->setWindowTitle(QStringLiteral("A Cosine Wave"));

    QComboBox *themeList = new QComboBox(widget);
    themeList->addItem(QStringLiteral("Qt"));
    themeList->addItem(QStringLiteral("Primary Colors"));
    themeList->addItem(QStringLiteral("Digia"));
    themeList->addItem(QStringLiteral("Stone Moss"));
    themeList->addItem(QStringLiteral("Army Blue"));
    themeList->addItem(QStringLiteral("Retro"));
    themeList->addItem(QStringLiteral("Ebony"));
    themeList->addItem(QStringLiteral("Isabelle"));
    themeList->setCurrentIndex(6);

    QPushButton *labelButton = new QPushButton(widget);
    labelButton->setText(QStringLiteral("Change label style"));

    QCheckBox *smoothCheckBox = new QCheckBox(widget);
    smoothCheckBox->setText(QStringLiteral("Smooth dots"));
    smoothCheckBox->setChecked(true);

    QComboBox *itemStyleList = new QComboBox(widget);
    itemStyleList->addItem(QStringLiteral("Sphere"), int(QAbstract3DSeries::MeshSphere));
    itemStyleList->addItem(QStringLiteral("Cube"), int(QAbstract3DSeries::MeshCube));
    itemStyleList->addItem(QStringLiteral("Minimal"), int(QAbstract3DSeries::MeshMinimal));
    itemStyleList->addItem(QStringLiteral("Point"), int(QAbstract3DSeries::MeshPoint));
    itemStyleList->setCurrentIndex(0);

    QPushButton *cameraButton = new QPushButton(widget);
    cameraButton->setText(QStringLiteral("Change camera preset"));

    QPushButton *itemCountButton = new QPushButton(widget);
    itemCountButton->setText(QStringLiteral("Toggle item count"));

    QPushButton *scaleButton = new QPushButton(widget);
    scaleButton->setText(QStringLiteral("Change Scale"));

    QCheckBox *backgroundCheckBox = new QCheckBox(widget);
    backgroundCheckBox->setText(QStringLiteral("Show background"));
    backgroundCheckBox->setChecked(true);

    QCheckBox *gridCheckBox = new QCheckBox(widget);
    gridCheckBox->setText(QStringLiteral("Show grid"));
    gridCheckBox->setChecked(true);

    QComboBox *shadowQuality = new QComboBox(widget);
    shadowQuality->addItem(QStringLiteral("None"));
    shadowQuality->addItem(QStringLiteral("Low"));
    shadowQuality->addItem(QStringLiteral("Medium"));
    shadowQuality->addItem(QStringLiteral("High"));
    shadowQuality->addItem(QStringLiteral("Low Soft"));
    shadowQuality->addItem(QStringLiteral("Medium Soft"));
    shadowQuality->addItem(QStringLiteral("High Soft"));
    shadowQuality->setCurrentIndex(4);

    QFontComboBox *fontList = new QFontComboBox(widget);
    fontList->setCurrentFont(QFont("Arial"));

    vLayout->addWidget(labelButton, 0, Qt::AlignTop);
    vLayout->addWidget(cameraButton, 0, Qt::AlignTop);
    vLayout->addWidget(itemCountButton, 0, Qt::AlignTop);
    vLayout->addWidget(backgroundCheckBox);
    vLayout->addWidget(gridCheckBox);
    vLayout->addWidget(smoothCheckBox, 0, Qt::AlignTop);
    vLayout->addWidget(new QLabel(QStringLiteral("Change dot style")));
    vLayout->addWidget(itemStyleList);
    vLayout->addWidget(new QLabel(QStringLiteral("Change theme")));
    vLayout->addWidget(themeList);
    vLayout->addWidget(new QLabel(QStringLiteral("Adjust shadow quality")));
    vLayout->addWidget(shadowQuality);
    vLayout->addWidget(new QLabel(QStringLiteral("Change font")));
    vLayout->addWidget(fontList, 1, Qt::AlignTop);
    vLayout->addWidget(scaleButton, 0, Qt::AlignTop);

    GraphDataModifier *modifier = new GraphDataModifier(view);

    QObject::connect(cameraButton, &QPushButton::clicked, modifier,
                     &GraphDataModifier::changePresetCamera);
    QObject::connect(labelButton, &QPushButton::clicked, modifier,
                     &GraphDataModifier::changeLabelStyle);
    QObject::connect(itemCountButton, &QPushButton::clicked, modifier,
                     &GraphDataModifier::toggleItemCount);

    QObject::connect(backgroundCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphDataModifier::setBackgroundEnabled);
    QObject::connect(gridCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphDataModifier::setGridEnabled);
    QObject::connect(smoothCheckBox, &QCheckBox::stateChanged, modifier,
                     &GraphDataModifier::setSmoothDots);

    QObject::connect(modifier, &GraphDataModifier::backgroundEnabledChanged,
                     backgroundCheckBox, &QCheckBox::setChecked);
    QObject::connect(modifier, &GraphDataModifier::gridEnabledChanged,
                     gridCheckBox, &QCheckBox::setChecked);
    QObject::connect(itemStyleList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeStyle(int)));

    QObject::connect(themeList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeTheme(int)));

    QObject::connect(shadowQuality, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeShadowQuality(int)));

    QObject::connect(modifier, &GraphDataModifier::shadowQualityChanged, shadowQuality,
                     &QComboBox::setCurrentIndex);
    QObject::connect(view, &Q3DScatter::shadowQualityChanged, modifier,
                     &GraphDataModifier::shadowQualityUpdatedByVisual);

    QObject::connect(fontList, &QFontComboBox::currentFontChanged, modifier,
                     &GraphDataModifier::changeFont);

    QObject::connect(modifier, &GraphDataModifier::fontChanged, fontList,
                     &QFontComboBox::setCurrentFont);
//    QObject::connect(scaleButton, &Q)
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
}

void MainWindow::graph(){
    qDebug() << "Graphing";
    QStringList scatterdata;
    scatterdata = MeshtalParser::parse_file(property->fileName);
    view->setFlags(view->flags() ^ Qt::FramelessWindowHint);
    QList<float> heat_values;
    for(int i = 1; i < scatterdata.size();++i){
        QtDataVisualization::QScatterDataArray data;
        QStringList splitline = scatterdata[i].split(",");
        data << QVector3D(splitline[1].toFloat(),splitline[2].toFloat(),splitline[3].toFloat());
        QtDataVisualization::QScatter3DSeries *series = new  QtDataVisualization::QScatter3DSeries;
        series->dataProxy()->addItems(data);
        series->setBaseColor(randomfunctions::calculate_color(splitline[4].toFloat()));
        view->addSeries(series);
        QString additional = splitline[4] + " " + "Region:" + splitline[0];
        series->setItemLabelFormat(QStringLiteral("@xTitle: @xLabel @yTitle: @yLabel @zTitle: @zLabel HRate:")+ additional);
        series->setMeshSmooth(1);
        qDebug() << splitline[1] << splitline[2] << splitline[3];
    }
    view->show();
    this->property->~Properties();
}
void MainWindow::color_graph(){

}

void MainWindow::on_actionOpen_triggered(){
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open File"), "", tr("Meshtal Files (*.csv *.meshtal *.xlsx)"));
    qDebug() << "That worked";
    qDebug()<< fileName;
    property = new Properties(this,fileName);
    property->setModal(true);
    property->exec();
    qDebug() << "That worked too";
}
void MainWindow::on_actionTFCoil_triggered(){
    property = new Properties(this, ":/examples/assets/example1.csv");
    property->setModal(true);
    property->exec();
}

