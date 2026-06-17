#include <iostream>
using namespace std;

class MediaFile {
public:
    string path;
    string size;
    bool isPlay;

    MediaFile(string p, string s, bool iP) : path(p), size(s), isPlay(iP) {}
    
    void play() {
        cout << "Playing: " << path << endl;
        isPlay = true;
    }
    
    void stop() {
        cout << "Stopped: " << path << endl;
        isPlay = false;
    }
};

// Virtual inheritance to solve diamond problem
class VisualMedia : public virtual MediaFile {  
public:
    string res;

    VisualMedia(string p, string s, bool iP, string r) 
        : MediaFile(p, s, iP), res(r) {}
};

class AudioMedia : public virtual MediaFile {  
public:
    int soundIntensity;
    
    AudioMedia(string p, string s, bool iP, int SI) 
        : MediaFile(p, s, iP), soundIntensity(SI) {}
};

class Images : public VisualMedia {
public:
    string type;
    
    Images(string p, string s, bool iP, string r, string t) 
        : MediaFile(p, s, iP), VisualMedia(p, s, iP, r), type(t) {}

    void display() {
        cout << "Displaying Image: " << path << ", Type: " << type << ", Resolution: " << res << endl;
    }
};

class Audio : public AudioMedia {
public:
    int speed;
    
    Audio(string p, string s, bool iP, int SI, int spd) 
        : MediaFile(p, s, iP), AudioMedia(p, s, iP, SI), speed(spd) {}

    void playAudio() {
        play();
        cout << "Audio Speed: " << speed << "x, Sound Intensity: " << soundIntensity << " Hz" << endl;
    }
};

class Videos : public VisualMedia, public AudioMedia {
public:
    bool subTitle;
    int speed;
    
    Videos(string p, string s, bool iP, string res, int SI, int spd, bool sub) 
        : MediaFile(p, s, iP), VisualMedia(p, s, iP, res), AudioMedia(p, s, iP, SI), speed(spd), subTitle(sub) {}

    void playVideo() {
        play();
        cout << "Video Resolution: " << res << ", Speed: " << speed << "x, Subtitles: " << (subTitle ? "ON" : "OFF") << endl;
    }
};

int main() {
    Images img("img.jpg", "2MB", false, "1080p", "PNG");
    Audio aud("song.mp3", "5MB", false, 44100, 1);
    Videos vid("movie.mp4", "1GB", false, "4K", 48000, 1, true);

    img.display();
    aud.playAudio();
    vid.playVideo();

    return 0;
}

