import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

StackView {
    id: root

    popEnter: Transition {
        XAnimator {
            from: (mainStack.mirrored ? -1 : 1) * -mainStack.width
            to: 0
            duration: 400
            easing.type: Easing.OutCubic
        }
    }

    popExit: Transition {
        XAnimator {
            from: 0
            to: (mainStack.mirrored ? -1 : 1) * mainStack.width
            duration: 400
            easing.type: Easing.OutCubic
        }
    }

    pushEnter: Transition {
        XAnimator {
            from: (mainStack.mirrored ? -1 : 1) * -mainStack.width
            to: 0
            duration: 400
            easing.type: Easing.OutCubic
        }
    }

    pushExit: Transition {
        XAnimator {
            from: 0
            to: (mainStack.mirrored ? -1 : 1) * mainStack.width
            duration: 400
            easing.type: Easing.OutCubic
        }
    }

}
