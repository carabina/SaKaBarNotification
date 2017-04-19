//
//  SaKaStatusBarNotification.h
//  StatusBarNotification
//
//  Created by 撒加 on 17/4/19.
//  Copyright © 2017年 撒加. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/**完成回调块*/
typedef void(^SaKaCompletionBlock)(void);
@interface SaKaScrollLabel : UILabel
- (CGFloat)scrollTime;
@end
@interface SaKaWindowContainer : UIWindow
/**通知高度*/
@property (assign, nonatomic) CGFloat notificationHeight;
@end

@interface SaKaViewController : UIViewController
@property (nonatomic) UIStatusBarStyle preferredStatusBarStyle;
/**横竖屏模式*/
@property (nonatomic, setter=setSupportedInterfaceOrientations:)
UIInterfaceOrientationMask supportedInterfaceOrientations;
@end
@interface SaKaStatusBarNotification : NSObject

typedef NS_ENUM(NSInteger, SaKaNotificationStyle) {
    /**在statusBar处*/
    SaKaNotificationStyleStatusBarNotification,
    /**在navigationBar处*/
    SaKaNotificationStyleNavigationBarNotification
};

typedef NS_ENUM(NSInteger, SaKaNotificationAnimationStyle) {
    /**顶部*/
    SaKaNotificationAnimationStyleTop,
    /**底部*/
    SaKaNotificationAnimationStyleBottom,
    /**左边*/
    SaKaNotificationAnimationStyleLeft,
    /**右边*/
    SaKaNotificationAnimationStyleRight
};

typedef NS_ENUM(NSInteger, SaKaNotificationAnimationType) {
    /**不覆盖原背景*/
    SaKaNotificationAnimationTypeReplace,
    /**覆盖原背景*/
    SaKaNotificationAnimationTypeOverlay
};

/**显示标签*/
@property (strong, nonatomic) SaKaScrollLabel *notificationLabel;
@property (strong, nonatomic) UIView *statusBarView;
/**点击回调块*/
@property (copy, nonatomic) SaKaCompletionBlock notificationTappedBlock;
/**是否正在显示*/
@property (nonatomic,readonly) BOOL notificationIsShowing;
/**是否正在消失*/
@property (nonatomic,readonly) BOOL notificationIsDismissing;
/**显示Window*/
@property (strong, nonatomic) SaKaWindowContainer *notificationWindow;
/**通知背景色*/
@property (strong, nonatomic) UIColor *notificationLabelBackgroundColor;
/**通知文本色*/
@property (strong, nonatomic) UIColor *notificationLabelTextColor;
/**通知文本字体*/
@property (strong, nonatomic) UIFont *notificationLabelFont;
/**通知文本高度*/
@property (assign, nonatomic) CGFloat notificationLabelHeight;
/**自定义view*/
@property (strong, nonatomic) UIView *customView;
/**是否带下划线*/
@property (assign, nonatomic) BOOL multiline;
/**支持方向*/
@property (nonatomic) UIInterfaceOrientationMask supportedInterfaceOrientations;
/**持续时间*/
@property (nonatomic) NSTimeInterval notificationAnimationDuration;
/**通知样式*/
@property (nonatomic) SaKaNotificationStyle notificationStyle;
/**通知动画出现样式*/
@property (nonatomic) SaKaNotificationAnimationStyle notificationAnimationInStyle;
/**通知动画消失样式*/
@property (nonatomic) SaKaNotificationAnimationStyle
notificationAnimationOutStyle;
/**是否覆盖掉背景,默认覆盖*/
@property (nonatomic) SaKaNotificationAnimationType notificationAnimationType;
@property (nonatomic) UIStatusBarStyle preferredStatusBarStyle;

- (void)displayNotificationWithMessage:(NSString *)message
                            completion:(void (^)(void))completion;

- (void)displayNotificationWithMessage:(NSString *)message
                           forDuration:(NSTimeInterval)duration;

- (void)displayNotificationWithAttributedString:(NSAttributedString *)
attributedString
                                     completion:(void (^)(void))completion;

- (void)displayNotificationWithAttributedString:(NSAttributedString *)
attributedString
                                    forDuration:(NSTimeInterval)duration;

- (void)displayNotificationWithView:(UIView *)view
                         completion:(void (^)(void))completion;

- (void)displayNotificationWithView:(UIView *)view
                        forDuration:(NSTimeInterval)duration;

- (void)dismissNotificationWithCompletion:(void(^)(void))completion;

- (void)dismissNotification;

@end
