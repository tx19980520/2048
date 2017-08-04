#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    void clean();
    void randomevent();
    bool win();
    ~mainWidget();

private:
    bool notchange();
    int hitboard[5][5];
    bool changed = true;
    int score = 0;
    int board[5][5];
    Ui::mainWidget *ui;
};

#endif // MAINWIDGET_H
