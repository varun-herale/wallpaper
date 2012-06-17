#include <QtGui>

#include "window.h"

Window::Window(QWidget *parent) : QDialog(parent)
{
  browseButton = createButton(tr("&Browse..."), SLOT(browse()));
  okayButton = createButton(tr("&Okay"), SLOT(okay()));
  
  imageComboBox = createComboBox();
  
  d = new Plasma::Containment();
  
  imageLabel = new QLabel(tr("Image Path:"));
  
  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->addWidget(imageLabel,0,0);
  mainLayout->addWidget(imageComboBox,0,1);
  mainLayout->addWidget(browseButton,1,0);
  mainLayout->addWidget(okayButton,1,1);
  setLayout(mainLayout);
  
  setWindowTitle(tr("Change Wallpaper"));
  resize(250,100);
}

void Window::browse()
{
  QString path = QFileDialog::getOpenFileName(this,
					      tr("Select Image"),
					      "/home", 
					      tr("Image Files (*.png *.jpeg *.jpg *.xcf *.svg *.svgz *.bmps)"));
  if(!path.isEmpty()) {
    if(imageComboBox->findText(path) == -1)
      imageComboBox->addItem(path);
    imageComboBox->setCurrentIndex(imageComboBox->findText(path));
  }
}
  
void Window::okay()
{
  QString imagePath = imageComboBox->currentText();
  
  KUrl url;
  url.addPath(imagePath);
  
  QDBusConnection bus = QDBusConnection::sessionBus();
  QDBusInterface *interface = new QDBusInterface("org.kde.kactivitymanagerd",
						 "/ActivityManager",
						 "org.kde.ActivityManager");
  QDBusReply<QString> reply = interface->call("CurrentActivity");
  
  QString current = reply;
  
  /*KConfig config("plasma-desktop-appletsrc");
  KConfigGroup cfg = config.group("Containments");
  
  foreach(const QString &name, cfg.groupList())
  {
    KConfigGroup contGrp(&cfg, name);
    if(contGrp.readEntry("activityId") == current)
    {
      group = contGrp;
    }
  }
  plugIn = Plasma::PluginLoader::pluginLoader();
  app = plugIn->loadApplet("desktop");
  d = qobject_cast<Plasma::Containment*>(const_cast<Plasma::Applet*>(app));*/
  
  qDebug() << (d->isContainment());
  //Output is false for above. What to do ?
  
  //qDebug() << group.readEntry("activityId", QString());
  
  //d->restore(group);
  
  //d = containmentForScreen(0,1);
  
  //d->wallpaper()->setUrls(url);
  //d->setWallpaper("image");
}

QPushButton *Window::createButton(const QString &text, const char *member)
{
  QPushButton *button = new QPushButton(text);
  connect(button, SIGNAL(clicked()), this, member);
  return button;
}

QComboBox *Window::createComboBox(const QString &text)
{
  QComboBox *comboBox = new QComboBox;
  comboBox->setEditable(true);
  comboBox->addItem(text);
  comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
  return comboBox;
}

















  
  
      