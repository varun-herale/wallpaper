#include <QtGui>

#include "window.h"

Window::Window(QWidget *parent) : QDialog(parent)
{
  browseButton = createButton(tr("&Browse..."), SLOT(browse()));
  okayButton = createButton(tr("&Okay"), SLOT(okay()));
  
  imageComboBox = createComboBox();
  
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
  url.addpath(imagePath);
  
  corona = Plasma::Applet::containment()->corona();
  screen = Plasma::Applet::containment()->screen();
  
  if(screen < 0)
    screen = 0;
  
  d = corona->containmentForScreen(screen);
  d->wallpaper()->setUrls(url);
  d->setWallpaper("image");
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

















  
  
      