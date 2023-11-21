package lmi;

class ObjectShadow {
    // MainFrame
    static projectawt.FrameController frameController_;

    // init()
    static void init(Object ... args) {
        frameController_ = (projectawt.FrameController)args[0];
    }
}
