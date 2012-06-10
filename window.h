#ifndef BROWSE_H
#define BROWSE_H

#include <QDialog>
#include <QDir>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsLayoutItem>

#include <Plasma/Containment>
#include <Plasma/Corona>
#include <Plasma/Wallpaper>

#include <kurl.h>

class Window : public QDialog
{
  Q_OBJECT
  
public:
  Window(QWidget *parent = 0)
  
private slots:
  void browse();
  void okay();
  
private:
  QComboBox *imageComboBox;
  QLabel *imageLabel;
  QPushButton *okayButton;
  QPushButton *browseButton;
  
  QDir currentDir;
  
  Plasma::Containment *d;
  Plasma::Corona *corona;
  int screen;
};

#endif