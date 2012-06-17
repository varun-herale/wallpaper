#ifndef BROWSE_H
#define BROWSE_H

#include <QDialog>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsLayoutItem>
#include <QDBusInterface>
#include <QDBusReply> 

#include <Plasma/Wallpaper>
#include <Plasma/Containment>

#include <kurl.h>
#include <KConfig>
#include <KConfigGroup>

class QComboBox;
class QLabel;
class QPushButton;

class Window : public QDialog
{
  Q_OBJECT
  
public:
  Window(QWidget *parent = 0);
  ~Window();
  
private slots:
  void browse();
  void okay();
  
private:
  QComboBox *imageComboBox;
  QLabel *imageLabel;
  QPushButton *okayButton;
  QPushButton *browseButton;
  QPushButton *createButton(const QString &text, const char *member);
  QComboBox *createComboBox(const QString &text = QString());
 
  KConfigGroup group;
  Plasma::Wallpaper *wp;
  KConfigGroup cfg;
  KConfigGroup grp;
};

#endif