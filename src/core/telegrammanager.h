/*

This file is part of Yottagram.
Copyright 2020, Michał Szczepaniak <m.szczepaniak.000@gmail.com>

Yottagram is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Yottagram is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Yottagram. If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef TELEGRAMSENDER_H
#define TELEGRAMSENDER_H

#include "telegramreceiver.h"
#include <QObject>
#include <QTimer>
#include <networkmanager.h>

using namespace std;

class TelegramManager : public QObject
{
    Q_OBJECT
public:
    TelegramManager();

    void init();
    void sendQuery(td_api::Function* message);
    qint32 getMyId() const;
    bool getDaemonEnabled() const;
    void setDaemonEnabled(bool daemonEnabled);
    void setNetworkType(QString networkType);
    QString getNetworkType() const;

signals:
    void onMessageReceived(quint64 id, td_api::Object* message);
    void send(td_api::Function* message);
    void updateNewChat(td_api::updateNewChat *newChat);
    void chats(td_api::chats *chats);
    void updateChatTitle(td_api::updateChatTitle *updateChatTitle);
    void updateChatPhoto(td_api::updateChatPhoto *updateChatPhoto);
    void updateChatLastMessage(td_api::updateChatLastMessage *updateChatLastMessage);
    void updateChatOrder(td_api::updateChatOrder *updateChatOrder);
    void updateFile(td_api::updateFile *updateFile);
    void updateChatReadInbox(td_api::updateChatReadInbox *updateChatReadInbox);
    void updateChatReadOutbox(td_api::updateChatReadOutbox *updateChatReadOutbox);
    void message(td_api::message *message);
    void messages(td_api::messages *messages);
    void updateNewMessage(td_api::updateNewMessage *updateNewMessage);
    void updateUser(td_api::updateUser *updateUser);
    void updateMessageSendSucceeded(td_api::updateMessageSendSucceeded *updateMessageSendSucceeded);
    void updateMessageContent(td_api::updateMessageContent *updateMessageContent);
    void updateDeleteMessages(td_api::updateDeleteMessages *updateDeleteMessages);
    void updateNotification(td_api::updateNotification *updateNotification);
    void updateNotificationGroup(td_api::updateNotificationGroup *updateNotificationGroup);
    void updateActiveNotifications(td_api::updateActiveNotifications *updateActiveNotifications);
    void updateHavePendingNotifications(td_api::updateHavePendingNotifications *updateHavePendingNotifications);
    void updateUserFullInfo(td_api::updateUserFullInfo *updateUserFullInfo);
    void updateBasicGroupFullInfo(td_api::updateBasicGroupFullInfo *updateBasicGroupFullInfo);
    void updateSupergroupFullInfo(td_api::updateSupergroupFullInfo *updateSupergroupFullInfo);
    void updateOption(td_api::updateOption *updateOption);
    void updateSecretChat(td_api::updateSecretChat *updateSecretChat);
    void updateBasicGroup(td_api::updateBasicGroup *updateBasicGroup);
    void updateSupergroup(td_api::updateSupergroup *updateSupergroup);
    void updateChatNotificationSettings(td_api::updateChatNotificationSettings *updateChatNotificationSettings);
    void updateScopeNotificationSettings(td_api::updateScopeNotificationSettings *updateScopeNotificationSettings);
    void autoDownloadSettingsPresets(td_api::autoDownloadSettingsPresets *autoDownloadSettingsPresets);
    void updateChatPinnedMessage(td_api::updateChatPinnedMessage *updateChatPinnedMessage);
    void updateInstalledStickerSets(td_api::updateInstalledStickerSets *updateInstalledStickerSets);
    void stickerSets(td_api::stickerSets *stickerSets);
    void stickerSet(td_api::stickerSet *stickerSet);
    void updateChatIsPinned(td_api::updateChatIsPinned *updateChatIsPinned);
    void updateChatPermissions(td_api::updateChatPermissions *updateChatPermissions);
    void updateUnreadChatCount(td_api::updateUnreadChatCount *updateUnreadChatCount);
    void updateUnreadMessageCount(td_api::updateUnreadMessageCount *updateUnreadMessageCount);

    void myIdChanged(qint32 myId);

public slots:
    void messageReceived(quint64 id, td_api::Object* message);
    void onUpdateOption(td_api::updateOption *updateOption);
    void defaultRouteChanged(NetworkService* networkService);

private:
    TelegramReceiver receiver;
    QThread receiverThread;
    QTimer incomingMessageCheckTimer;
    qint32 _myId;
    NetworkManager* _networkManager;
    QString _networkType;
};

#endif // TELEGRAMSENDER_H
