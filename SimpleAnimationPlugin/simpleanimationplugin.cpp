#include "simpleanimationplugin.h"

SimpleAnimationPlugin::SimpleAnimationPlugin()
{
    rectAdded = false;
}

void SimpleAnimationPlugin::draw(QGraphicsScene &scene)
{
    if (!rectAdded)
    {
        this->rectangle = scene.addRect(0,0,10,10);//.addRect(100, 0, 80, 100);
        this->rectAdded = true;
    }
    else
    {
       this->rectangle->setPos(rectangle->x() + 1, rectangle->y());
    }
}

int SimpleAnimationPlugin::refreshSpeed() { return 100; }

PluginInterface* SimpleAnimationPluginFactory::getInstance()
{
  return new SimpleAnimationPlugin();
}
