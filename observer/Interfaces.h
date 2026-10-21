#pragma once   // 同じファイルが二重に読み込まれるのを防ぐ

class Observer {
public:
    Observer() = default;
    Observer(const Observer&) = delete;             // コピー禁止（理由は後述）
    Observer& operator=(const Observer&) = delete;
    virtual ~Observer() = default;

    virtual void update(float temperature, float humidity, float pressure) = 0;
};

class Subject {
public:
    Subject() = default;
    Subject(const Subject&) = delete;
    Subject& operator=(const Subject&) = delete;
    virtual ~Subject() = default;

    virtual void registerObserver(Observer& o) = 0;
    virtual void removeObserver(Observer& o) = 0;
    virtual void notifyObservers() = 0;
};

class DisplayElement {
public:
    virtual ~DisplayElement() = default;

    virtual void display() const = 0;   // const = 自分の中身を書き換えない約束
};