#include <QtCore/QString>
#include <Server.h>
#include <ServerUser.h>

#ifndef MUMBLE_MURMUR_EMOTE_H_
#define MUMBLE_MURMUR_EMOTE_H_


// TODO: Make most of the member variables private
class Emote {
    public:
        //Emote(std::string);
        Emote(QString);
        Emote();
        ~Emote();

        // Perform emote replacement for the current emote
        QString insertEmote(QString);
        QString getImageTag();
        
        QString filename; // The filename of the emote
        QString name; // Name used to trigger emote replacement
        QByteArray data64; // A base64 encoded QString of the emote picture
};

#endif
