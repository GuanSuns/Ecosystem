#-------------------------------------------------
#
# Project created by QtCreator 2016-03-14T21:35:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EcosystemWithUI
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    scrollqgraphicsview.cpp \
    Ecosystem/BasicAnimal.cpp \
    Ecosystem/BasicPlant.cpp \
    Ecosystem/BasicState.cpp \
    Ecosystem/Carnivore.cpp \
    Ecosystem/Carnivore_GlobalStates.cpp \
    Ecosystem/CarnivoreStates_AtRest.cpp \
    Ecosystem/CarnivoreStates_Escape.cpp \
    Ecosystem/CarnivoreStates_FindFood.cpp \
    Ecosystem/CarnivoreStates_FindWater.cpp \
    Ecosystem/Creature.cpp \
    Ecosystem/CreatureVector.cpp \
    Ecosystem/Herbivore.cpp \
    Ecosystem/Herbivore_GlobalStates.cpp \
    Ecosystem/HerbivoreStates_AtRest.cpp \
    Ecosystem/HerbivoreStates_Escape.cpp \
    Ecosystem/HerbivoreStates_FindFood.cpp \
    Ecosystem/HerbivoreStates_FindWater.cpp \
    Ecosystem/InfoDispatchMachine.cpp \
    Ecosystem/MapItem.cpp \
    Ecosystem/MemorySystem.cpp \
    Ecosystem/Parameters.cpp \
    Ecosystem/Random.cpp \
    Ecosystem/Vector2D.cpp \
    creatureitem.cpp \
    ecosystemscene.cpp \
    statisticsscene.cpp \
    initialwater.cpp \
    initialplant.cpp \
    initialanimal.cpp \
    Ecosystem/BasicAnimal.cpp \
    Ecosystem/BasicPlant.cpp \
    Ecosystem/BasicState.cpp \
    Ecosystem/Carnivore.cpp \
    Ecosystem/Carnivore_GlobalStates.cpp \
    Ecosystem/CarnivoreStates_AtRest.cpp \
    Ecosystem/CarnivoreStates_Escape.cpp \
    Ecosystem/CarnivoreStates_FindFood.cpp \
    Ecosystem/CarnivoreStates_FindWater.cpp \
    Ecosystem/Creature.cpp \
    Ecosystem/CreatureVector.cpp \
    Ecosystem/Herbivore.cpp \
    Ecosystem/Herbivore_GlobalStates.cpp \
    Ecosystem/HerbivoreStates_AtRest.cpp \
    Ecosystem/HerbivoreStates_Escape.cpp \
    Ecosystem/HerbivoreStates_FindFood.cpp \
    Ecosystem/HerbivoreStates_FindWater.cpp \
    Ecosystem/InfoDispatchMachine.cpp \
    Ecosystem/MapItem.cpp \
    Ecosystem/MemorySystem.cpp \
    Ecosystem/Parameters.cpp \
    Ecosystem/Random.cpp \
    Ecosystem/Vector2D.cpp

HEADERS  += mainwindow.h \
    scrollqgraphicsview.h \
    Ecosystem/BasicAnimal.h \
    Ecosystem/BasicPlant.h \
    Ecosystem/BasicState.h \
    Ecosystem/Carnivore.h \
    Ecosystem/Carnivore_GlobalStates.h \
    Ecosystem/CarnivoreStates_AtRest.h \
    Ecosystem/CarnivoreStates_Escape.h \
    Ecosystem/CarnivoreStates_FindFood.h \
    Ecosystem/CarnivoreStates_FindWater.h \
    Ecosystem/Creature.h \
    Ecosystem/CreatureVector.h \
    Ecosystem/Herbivore.h \
    Ecosystem/Herbivore_GlobalStates.h \
    Ecosystem/HerbivoreStates_AtRest.h \
    Ecosystem/HerbivoreStates_Escape.h \
    Ecosystem/HerbivoreStates_FindFood.h \
    Ecosystem/HerbivoreStates_FindWater.h \
    Ecosystem/InfoDispatchMachine.h \
    Ecosystem/Location.h \
    Ecosystem/MapItem.h \
    Ecosystem/MemorySystem.h \
    Ecosystem/Parameters.h \
    Ecosystem/Random.h \
    Ecosystem/Vector2D.h \
    creatureitem.h \
    ecosystemscene.h \
    statisticsscene.h \
    initialwater.h \
    initialplant.h \
    initialanimal.h \
    Ecosystem/BasicAnimal.h \
    Ecosystem/BasicPlant.h \
    Ecosystem/BasicState.h \
    Ecosystem/Carnivore.h \
    Ecosystem/Carnivore_GlobalStates.h \
    Ecosystem/CarnivoreStates_AtRest.h \
    Ecosystem/CarnivoreStates_Escape.h \
    Ecosystem/CarnivoreStates_FindFood.h \
    Ecosystem/CarnivoreStates_FindWater.h \
    Ecosystem/Creature.h \
    Ecosystem/CreatureVector.h \
    Ecosystem/Herbivore.h \
    Ecosystem/Herbivore_GlobalStates.h \
    Ecosystem/HerbivoreStates_AtRest.h \
    Ecosystem/HerbivoreStates_Escape.h \
    Ecosystem/HerbivoreStates_FindFood.h \
    Ecosystem/HerbivoreStates_FindWater.h \
    Ecosystem/InfoDispatchMachine.h \
    Ecosystem/Location.h \
    Ecosystem/MapItem.h \
    Ecosystem/MemorySystem.h \
    Ecosystem/Parameters.h \
    Ecosystem/Random.h \
    Ecosystem/Vector2D.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
