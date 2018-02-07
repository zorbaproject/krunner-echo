
#ifndef ECHO_H
#define ECHO_H

#include <KRunner/AbstractRunner>

class Echo : public Plasma::AbstractRunner
{
    Q_OBJECT

public:
    Echo(QObject *parent, const QVariantList &args);
    ~Echo();

    void match(Plasma::RunnerContext &);
    void run(const Plasma::RunnerContext &, const Plasma::QueryMatch &);
    void reloadConfiguration();

private:
    QString m_triggerWord;
};

K_EXPORT_PLASMA_RUNNER(echo, Echo)

#endif
