#include "mainwindow.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  MainWindow window;

  window.resize(600, 500);
  window.setWindowTitle("Recepy Streamline");
  window.show();

  return app.exec();
}
