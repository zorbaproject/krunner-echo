
#include "main.h"

#include <KLocalizedString>
#include <QApplication>
#include <QClipboard>

Echo::Echo(QObject *parent, const QVariantList &args)
    : Plasma::AbstractRunner(parent, args)
{
    Q_UNUSED(args);
    
    setObjectName(QLatin1String("Echo"));
    reloadConfiguration();
    setHasRunOptions(true);
    setIgnoredTypes(Plasma::RunnerContext::Directory |
                    Plasma::RunnerContext::File |
                    Plasma::RunnerContext::NetworkLocation);
    setSpeed(AbstractRunner::SlowSpeed);
    setPriority(HighestPriority);
    setDefaultSyntax(Plasma::RunnerSyntax(QString("Echo :q:"), i18n("Repeats :q:.")));
}

Echo::~Echo()
{
}

void Echo::match(Plasma::RunnerContext &context)
{
    QString text = context.query();
    
    if (!context.isValid()) return;
    
    if (text.contains(" ")) {
        QList<Plasma::QueryMatch> matches;
        float relevance = 1;
        QString s = text.replace("Echo ", "", Qt::CaseInsensitive);
        if (s.size() > 0) {
            relevance -= 0.01;
            Plasma::QueryMatch match(this);
            match.setType(Plasma::QueryMatch::InformationalMatch);
            match.setIcon(QIcon::fromTheme("konversation"));
            match.setText(s);
            match.setRelevance(relevance);
            matches.append(match);
        }
        context.addMatches(matches);
    }
}

void Echo::run(const Plasma::RunnerContext &context, const Plasma::QueryMatch &match)
{
    Q_UNUSED(context);
    QApplication::clipboard()->setText(match.text());
}

void Echo::reloadConfiguration()
{
    //nothing
}

#include "moc_main.cpp"
