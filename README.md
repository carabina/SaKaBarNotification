# SaKaBarNotification
a notification of statusBar or navigationBar

StatusBar Forexample:

 SaKaStatusBarNotification *notification = [SaKaStatusBarNotification new];
    notification.notificationStyle = SaKaNotificationStyleNavigationBarNotification;
    notification.notificationAnimationInStyle = SaKaNotificationAnimationStyleBottom;
    notification.notificationAnimationOutStyle = SaKaNotificationAnimationStyleBottom;
    notification.multiline = YES;
    notification.notificationTappedBlock = ^(void) {
    };
    [notification displayNotificationWithMessage:@"Are you crazy ?" forDuration:5.0f];

NavigationBar Forexample:

SaKaNavigationBarNotification *notification = [SaKaNavigationBarNotification defaultNavigationBarNotification];
    notification.delegate = self;
    [notification showWithMessage:@"Are you crazy , too ?" Duration:5.0f  InView:self.tableView];

Also can get the delegate Method :

- (void)navigationBarNotificationWillShow:(SaKaNavigationBarNotification *)notification StartDate:(NSDate *)start{
    NSLog(@"notification will show");
    NSLog(@"%@",start);
}

- (void)navigationBarNotificationIsTapped:(SaKaNavigationBarNotification *)notification {
    NSLog(@"notification is tapped");

}

- (void)navigationBarNotificationIsDismissed:(SaKaNavigationBarNotification *)notification {
    NSLog(@"notification is Dismissed");
}