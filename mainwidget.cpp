#include "mainwidget.h"
#include "ui_mainwidget.h"

//全局变量
QString now_user_name;
int now_user_id;

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    menuwidget = new MenuWidget;
    loginwidget = new LoginWidget;
    signupwidget = new Signupwidget;
    fileswidget = new FilesWidget;
    selectmodewidget = new SelectModeWidget;
    sortwidget = new SortWidget;
    stackLayout = new QStackedLayout;
    singlemode = new SingleMode;
    seriesmode = new SeriesMode ;
    modifymode = new ModifyMode ;
    addmode = new Addmode;


    stackLayout->addWidget(menuwidget);         //0
    stackLayout->addWidget(loginwidget);        //1
    stackLayout->addWidget(selectmodewidget);   //2
    stackLayout->addWidget(fileswidget);        //3
    stackLayout->addWidget(sortwidget);         //4
    stackLayout->addWidget(signupwidget);       //5

    stackLayout->addWidget(singlemode);         //6
    stackLayout->addWidget(seriesmode);         //7
    stackLayout->addWidget(modifymode);         //8
    stackLayout->addWidget(addmode);            //9


    setLayout(stackLayout);


    connect(menuwidget, &MenuWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(loginwidget, &LoginWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);

    connect(loginwidget, &LoginWidget::idchange, fileswidget, &FilesWidget::initForm);
    connect(loginwidget, &LoginWidget::idchange, fileswidget, &FilesWidget::initTable);

    connect(fileswidget, &FilesWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(selectmodewidget, &SelectModeWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(sortwidget, &SortWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(signupwidget, &Signupwidget::display, stackLayout, &QStackedLayout::setCurrentIndex);

    connect(singlemode, &SingleMode::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(seriesmode, &SeriesMode::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(modifymode, &ModifyMode::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(addmode, &Addmode::display, stackLayout, &QStackedLayout::setCurrentIndex);
}

MainWidget::~MainWidget()
{
    delete ui;
}
