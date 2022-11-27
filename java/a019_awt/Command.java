package lmi;

import java.util.Set;
import java.util.TreeMap;

import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

import java.awt.event.MouseEvent;
import java.awt.event.KeyEvent;

class Command {
    // type define
    private static class CommandMap extends TreeMap<String, Method> {};

    // fields
    private static CommandMap map_;

    // commands
    static Void commandTemplate() {
        // code here...

        return null;
    }

    static Void helloWorld() {
        System.out.println("Hello, world!");

        return null;
    }

    static Void toggleVisibleOfFrame() {
        boolean visible = ObjectShadow.frameController_.frame_.isVisible();
        ObjectShadow.frameController_.frame_.setVisible(!visible);

        return null;
    }

    static int count = 0;
    static Void setLabelText() {
        ++count;
        ((java.awt.Label)ObjectShadow.frameController_.frame_.getComponent(0)).setText(String.valueOf(count));

        return null;
    }

    static Void printFrame() {
        Debug.debugDescribe(ObjectShadow.frameController_.frame_.toString());

        return null;
    }

    static Void generateKeyPushUpCtrlE() {
        generateControlModifierKeyPushUpCtrlE();

        return null;
    }

    static Void generateKeyPushUpEnter() {
        generateKeyEvent(KeyEvent.KEY_PRESSED, 0, KeyEvent.VK_ENTER, '\012', KeyEvent.KEY_LOCATION_STANDARD);
        generateKeyEvent(KeyEvent.KEY_TYPED, 0, KeyEvent.VK_UNDEFINED, '\012', KeyEvent.KEY_LOCATION_UNKNOWN);
        generateKeyEvent(KeyEvent.KEY_RELEASED, 0, KeyEvent.VK_ENTER, '\012', KeyEvent.KEY_LOCATION_STANDARD);

        return null;
    }

    static Void click() {
        generateMouseClick();

        return null;
    }

    // package method
    /// all methods with default access modifier will count on as executable command
    public static void init() {
        map_ = new CommandMap();
        Method methodArray[] = Command.class.getDeclaredMethods();
        for (Method method : methodArray) {
            if (!lmi.Util.methodHasModifier(method, Modifier.PUBLIC)
                    && !lmi.Util.methodHasModifier(method, Modifier.PRIVATE)) {
                map_.put(method.getName(), method);
            }
        }
    }

    public static Method getCommandByString(String commandString) {
        return map_.get(commandString);
    }

    public static Set<String> getCommandStringSet() {
        return map_.keySet();
    }

    // private methods
    private static void generateKeyEvent(int id, int modifiers, int keyCode, char keyChar, int keyLocation) {
        KeyEvent event = new KeyEvent(
                ObjectShadow.frameController_.frame_,
                id,
                System.currentTimeMillis(),
                modifiers,
                keyCode,
                keyChar,
                keyLocation);

        lmi.Debug.debugDescribe(event.toString());
        System.out.println(event.getModifiersEx());
    }

    private static void generateControlModifierKeyPushUpCtrlE() {
        generateKeyEvent(KeyEvent.KEY_PRESSED, KeyEvent.CTRL_DOWN_MASK, KeyEvent.VK_CONTROL, KeyEvent.CHAR_UNDEFINED, KeyEvent.KEY_LOCATION_LEFT);
        generateKeyEvent(KeyEvent.KEY_PRESSED, KeyEvent.CTRL_DOWN_MASK, KeyEvent.VK_E, '\u0005', KeyEvent.KEY_LOCATION_STANDARD);
        generateKeyEvent(KeyEvent.KEY_TYPED, KeyEvent.CTRL_DOWN_MASK, KeyEvent.VK_UNDEFINED, '\u0005', KeyEvent.KEY_LOCATION_UNKNOWN);
        generateKeyEvent(KeyEvent.KEY_RELEASED, KeyEvent.CTRL_DOWN_MASK, KeyEvent.VK_E, '\u0005', KeyEvent.KEY_LOCATION_STANDARD);
        generateKeyEvent(KeyEvent.KEY_RELEASED, 0, KeyEvent.VK_CONTROL, KeyEvent.CHAR_UNDEFINED, KeyEvent.KEY_LOCATION_LEFT);
    }

    private static void generateMouseClick() {
        generateKeyEvent(KeyEvent.KEY_PRESSED, KeyEvent.CTRL_DOWN_MASK, KeyEvent.VK_CONTROL, KeyEvent.CHAR_UNDEFINED, KeyEvent.KEY_LOCATION_LEFT);
        generateMouseEvent(
                MouseEvent.MOUSE_PRESSED,
                KeyEvent.CTRL_DOWN_MASK | MouseEvent.BUTTON1_DOWN_MASK,
                100,
                100,
                1,
                false,
                MouseEvent.BUTTON1);
        generateMouseEvent(
                MouseEvent.MOUSE_RELEASED,
                KeyEvent.CTRL_DOWN_MASK,
                100,
                100,
                1,
                false,
                MouseEvent.BUTTON1);
        generateMouseEvent(
                MouseEvent.MOUSE_CLICKED,
                KeyEvent.CTRL_DOWN_MASK,
                100,
                100,
                1,
                false,
                MouseEvent.BUTTON1);
        generateKeyEvent(KeyEvent.KEY_RELEASED, 0, KeyEvent.VK_CONTROL, KeyEvent.CHAR_UNDEFINED, KeyEvent.KEY_LOCATION_LEFT);
    }

    private static void generateMouseEvent(int id, int modifiers, int x, int y, int clickCount, boolean popupTrigger, int button) {
        MouseEvent event = new MouseEvent(
                ObjectShadow.frameController_.frame_,
                id,
                System.currentTimeMillis(),
                modifiers,
                x,
                y,
                clickCount,
                popupTrigger,
                button);

        lmi.Debug.debugDescribe(event.toString());
    }
}
