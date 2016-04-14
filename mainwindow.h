#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

private slots:
    //capture button
    void on_captureButton_clicked();
    //menu entries
    void exit();
    void startCapture();
    void stopCapture();
    void saveCapture();
private:
    Ui::MainWindow *ui;
    //helper functions for QMenu creation
    void createActions();
    void createMenus();
    //menus and actions associated with
    QMenu *fileMenu;
    QMenu *captureMenu;
    QAction *exitAct;
    QAction *startAct;
    QAction *stopAct;
    QAction *saveAct;
};

#endif // MAINWINDOW_H
