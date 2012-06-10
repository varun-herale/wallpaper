#include <QtGui>

#include "window.h"

Window::Window(QWidget *parent) : QDialog(parent)
{
  browseButton = createButton(tr("&Browse..."), SLOT(browse()));
  okayButton = createButton(tr("&Okay"), SLOT(okay()));
  
  imageComboBox = createComboBox();
  
  imageLabel = new QLabel(tr("Image Path:"));
  
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
  
      