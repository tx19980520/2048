#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QtGlobal>
#include <QStack>
#include <QTime>
#include <QMessageBox>
mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);

}

mainWidget::~mainWidget()
{
    delete ui;
}
void mainWidget::clean()
{
    for(int i=0;i <= 4; ++i)
    {
        for(int j=0; j <= 4; ++j)
        {
            board[i][j] = 0;
        }
    }
    randomevent();
    ui->label->setText("Score:"+QString::number(score));
    ui->pos11->setText(QString::number(board[1][1]));
    ui->pos12->setText(QString::number(board[1][2]));
    ui->pos13->setText(QString::number(board[1][3]));
    ui->pos14->setText(QString::number(board[1][4]));
    ui->pos21->setText(QString::number(board[2][1]));
    ui->pos22->setText(QString::number(board[2][2]));
    ui->pos23->setText(QString::number(board[2][3]));
    ui->pos24->setText(QString::number(board[2][4]));
    ui->pos31->setText(QString::number(board[3][1]));
    ui->pos32->setText(QString::number(board[3][2]));
    ui->pos33->setText(QString::number(board[3][3]));
    ui->pos34->setText(QString::number(board[3][4]));
    ui->pos41->setText(QString::number(board[4][1]));
    ui->pos42->setText(QString::number(board[4][2]));
    ui->pos43->setText(QString::number(board[4][3]));
    ui->pos44->setText(QString::number(board[4][4]));
}
void mainWidget::randomevent()
{
    int a, b, c;
    int count = 0;
    for(int i=1; i<= 4; ++i)
    {
        for(int j = 1; j <= 4; ++j)
        {
            if(board[i][j] != 0)
                ++count;
        }
    }
    if(count != 16)
    {
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
     do
     {
         count++;
         a = qrand()%3+1;
         b = qrand()%3+1;
     }
     while(board[a][b] != 0);
     c = (qrand()%2+1)*2;
     board[a][b] = c;
    }
    else{
        changed = false;
        return;
    }
}
void mainWidget::keyPressEvent(QKeyEvent *event)
{
    for(int i=1;i<=4;++i)
    {
        for(int j =1;j <= 4; ++j)
        {
            hitboard[i][j] = board[i][j];
        }
    }
    if(event->key() == Qt::Key_Left)
    {
        QStack<int> stack;
        for(int i=1 ; i<=4;++i)
        {
            stack.clear();
            for(int j=4; j >= 1; --j)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int j = 1;j <= 4; ++j)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
        for(int i=1; i <= 4; ++i)
        {
            for(int j=1; j <= 3; ++j)
            {
                if(board[i][j] == board[i][j+1] )
                {
                    board[i][j] = 2*board[i][j];
                    board[i][j+1] = 0;
                    score += board[i][j];
                }
            }
            if(!notchange())
            {
                randomevent();
            }
        }

        for(int i=1 ; i<=4;++i)
        {
            stack.clear();
            for(int j=4; j >= 1; --j)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int j = 1;j <= 4; ++j)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
    }
    if(event->key() == Qt::Key_Right)
    {
        QStack<int> stack;
        for(int i=1 ; i<=4;++i)
        {
            stack.clear();
            for(int j=1 ;j <= 4; ++j)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int j = 4;j >= 1; --j)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
        for(int i=1; i <= 4; ++i)
        {
            for(int j=4; j >= 2; --j)
            {
                if(board[i][j] == board[i][j-1])
                {
                    board[i][j] = 2*board[i][j];
                    board[i][j-1] = 0;
                    score += board[i][j];
                }
            }

        }

        for(int i=1 ; i<=4;++i)
        {
            stack.clear();
            for(int j=1 ;j <= 4; ++j)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int j = 4;j >= 1; --j)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
        if(!notchange())
        {
            randomevent();
        }
    }
    if(event->key() == Qt::Key_Up)
    {

        QStack<int> stack;
        for(int j=1 ; j<=4; ++j)
        {
            stack.clear();
            for(int i=4 ;i >= 1; --i)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int i = 1;i <= 4; ++i)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
        for(int j=1; j <= 4; ++j)//hang
        {
            for(int i=1; i <= 3; ++i)//lie
            {
                if(board[i][j] == board[i+1][j])
                {
                    board[i][j] = 2*board[i][j];
                    board[i+1][j] = 0;
                    score += board[i][j];
                }
            }

        }

        for(int j=1 ; j<=4; ++j)
        {
            stack.clear();
            for(int i=4 ;i >= 1; --i)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int i = 1;i <= 4; ++i)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
        if(!notchange())
        {
            randomevent();
        }
    }

    if(event->key() == Qt::Key_Down)
    {

        QStack<int> stack;
        for(int j=1 ; j<=4;++j)
        {
            stack.clear();
            for(int i=1 ;i <= 4;++i)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int i = 4;i >= 1; --i)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
        for(int j=1; j <= 4; ++j)//hang
        {
            for(int i=4; i >= 2; --i)//lie
            {
                if(board[i][j] == board[i-1][j])
                {
                    board[i][j] = 2*board[i][j];
                    board[i-1][j] = 0;
                    score += board[i][j];
                }
            }

        }

        for(int j=1 ; j<=4;++j)
        {
            stack.clear();
            for(int i=1 ;i <= 4;++i)
            {
                if(board[i][j] != 0)
                {
                    stack.push(board[i][j]);
                }
            }
            for(int i = 4;i >= 1; --i)
            {
                if(!stack.isEmpty())
                {
                    board[i][j] = stack.top();
                    stack.pop();
                }
                else board[i][j] = 0;
            }
        }
        if(!notchange())
        {
            randomevent();
        }
    }
    ui->label->setText("Score:"+QString::number(score));
    ui->pos11->setText(QString::number(board[1][1]));
    ui->pos12->setText(QString::number(board[1][2]));
    ui->pos13->setText(QString::number(board[1][3]));
    ui->pos14->setText(QString::number(board[1][4]));
    ui->pos21->setText(QString::number(board[2][1]));
    ui->pos22->setText(QString::number(board[2][2]));
    ui->pos23->setText(QString::number(board[2][3]));
    ui->pos24->setText(QString::number(board[2][4]));
    ui->pos31->setText(QString::number(board[3][1]));
    ui->pos32->setText(QString::number(board[3][2]));
    ui->pos33->setText(QString::number(board[3][3]));
    ui->pos34->setText(QString::number(board[3][4]));
    ui->pos41->setText(QString::number(board[4][1]));
    ui->pos42->setText(QString::number(board[4][2]));
    ui->pos43->setText(QString::number(board[4][3]));
    ui->pos44->setText(QString::number(board[4][4]));
    if(!changed)
    {
        int ret=QMessageBox::information(this,tr("game over!"),tr("you lose"),QMessageBox::Ok);
        if(ret == QMessageBox::Ok)
        {
            clean();
        }
    }
    if(win())
    {
        int ret=QMessageBox::information(this,tr("game over!"),tr("you win"),QMessageBox::Ok);
        if(ret == QMessageBox::Ok)
        {
            clean();
        }
    }
    update();
}

void mainWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(int i=200;i<=600; i += 100)
    {
        painter.drawLine(QPoint(i,150),QPoint(i,550));
    }
    for(int j= 150;j<=550;j += 100)
    {
        painter.drawLine(QPoint(200,j),QPoint(600,j));
    }
    update();
}

bool mainWidget::win()
{
    for(int i=1; i <= 4; ++i)
    {
        for(int j=1;j <= 4; ++j)
        {
            if(board[i][j] == 2048)
                return true;
        }
    }
    return false;
}
bool mainWidget::notchange()
{
    for(int i=1;i<=4;++i)
    {
        for(int j=1; j <= 4; ++j)
        {
            if(hitboard[i][j] != board[i][j])
                return false;
        }
    }
    return true;
}
