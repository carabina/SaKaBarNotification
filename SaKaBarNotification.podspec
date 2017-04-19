
Pod::Spec.new do |s|

  s.name         = "SaKaBarNotification"

  s.version      = "v1.0.0"

  s.summary      = "A Notification Label for NavigationBar Or StatusBar"

  s.homepage     = "https://github.com/WeiKunChao/SaKaBarNotification"

  s.license= { :type => "MIT", :file => "LICENSE" }

  s.author             = { "WeiKunChao" => "17736289336@163.com" }

  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/WeiKunChao/SaKaBarNotification.git", :tag => "v1.0.0" }

  s.source_files  =  "BarNotification/**/*.{h,m}"

  s.public_header_files = "BarNotification/**/*.h"

  s.framework  = "UIKit"

  s.requires_arc = true


end
