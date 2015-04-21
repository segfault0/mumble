#include <fstream>
#include <QtCore/QFileInfo>
#include <QtCore/QFile>
#include <QtCore/QByteArray>
#include <QtCore/QIODevice>
#include "Emote.h"

Emote::~Emote() { }

Emote::Emote() {
    filename = "";
    name = "";
    data64 = "";
}

//Emote::Emote(std::string filename) {
//    this->Emote(QString(filename));
//}

// Read the picture file at the given filename, convert to base64, and store it in the
// member variable data64
Emote::Emote(QString aFilename) {
    
    // Get the name as everything except the file extension
    QFileInfo fileInfo = QFileInfo(aFilename);
    this->name = fileInfo.baseName();
    this->filename = aFilename;

    QFile qFile(filename);
    qFile.open(QIODevice::ReadOnly);
    QByteArray byteArray = qFile.readAll();
    this->data64 = byteArray.toBase64();
}

QString Emote::insertEmote(QString msg) {
    int emoteStart = msg.indexOf(this->name);
    int emoteLength = this->name.length();
    while(emoteStart >= 0) {
        msg = msg.replace(emoteStart, emoteLength, this->getImageTag());
        emoteStart = msg.indexOf(this->name);
    }
    return msg;
}


QString Emote::getImageTag() {
    // TODO: Capture actual file extension in constructor and use here eventually?
    return "<img src='data:image/png;base64," + this->data64 + "'/>";
}
