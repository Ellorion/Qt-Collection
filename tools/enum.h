/**
 * License: Open-Source
 *
 * Usage:
 * // must be defined globally and in a header file
 * // so Qt can create a metaobject via moc
 * DefEnum(Test, A, B);
 *
 * // Reading:
 * QString test1 = enumToString(Test::A);
 * qDebug() << test1;
 * qDebug() << stringToEnum<Test>(test1);
 *
 * QString test2 = enumToString(Test::B);
 * qDebug() << test2;
 * qDebug() << stringToEnum<Test>(test2);
 *
 * int count = enumCount<Test>();
 * qDebug() << count;
 *
 * Iterate:
 * for(int i = 0; i < enumCount<Test>(); ++i) {
 *     qDebug() << Test(i);
 * }
 *
 **/

#pragma once

#include <QMetaEnum>
#include <QObject>

// inside an own class, that creates a metaobject
#define DefEnumLocal(_name, ...)                                                                                            \
  public:                                                                                                                   \
    enum class _name { __VA_ARGS__ };                                                                                       \
    Q_ENUM(_name)

// used globally
#define DefEnum(_name, ...)                                                                                                 \
    class ClassEnum##_name : public QObject {                                                                               \
        Q_OBJECT                                                                                                            \
                                                                                                                            \
      public:                                                                                                               \
        enum class _name { __VA_ARGS__ };                                                                                   \
        Q_ENUM(_name)                                                                                                       \
    };                                                                                                                      \
    typedef ClassEnum##_name::_name _name;

template <class T>
inline QString enumToString(T value) {
    return QMetaEnum::fromType<T>().valueToKey(int(value));
}

template <class T>
inline T stringToEnum(const QString &key) {
    return T(QMetaEnum::fromType<T>().keyToValue(key.toLatin1().data()));
}

template <class T>
inline int enumCount() {
    return QMetaEnum::fromType<T>().keyCount();
}
