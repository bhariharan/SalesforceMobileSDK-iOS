Pod::Spec.new do |s|

  s.name         = "SalesforceSDKCommon"
  s.version      = "7.0.0"
  s.summary      = "Salesforce Mobile SDK for iOS"
  s.homepage     = "https://github.com/forcedotcom/SalesforceMobileSDK-iOS"

  s.license      = { :type => "Salesforce.com Mobile SDK License", :file => "LICENSE.md" }
  s.author       = { "Raj Rao" => "rao.r@salesforce.com" }

  s.platform     = :ios, "11.0"

  s.source       = { :git => "https://github.com/forcedotcom/SalesforceMobileSDK-iOS.git",
                     :tag => "v#{s.version}",
                     :submodules => true }

  s.requires_arc = true
  s.default_subspec  = 'SalesforceSDKCommon'

  s.subspec 'SalesforceSDKCommon' do |sdkcommon|
      sdkcommon.dependency 'SalesforceSDKCommon'
      sdkcommon.source_files = 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/**/*.{h,m}', 'libs/SalesforceAnalytics/SalesforceSDKCommon/SalesforceSDKCommon.h'
      sdkcommon.public_header_files =
      'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFSDKSafeMutableSet.h','libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFTestContext.h','libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFSDKSafeMutableDictionary.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFPathUtil.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFSwiftDetectUtil.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFSDKSafeMutableArray.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFFileProtectionHelper.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Logger/SFLogger.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/NSUserDefaults+SFAdditions.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFSDKDatasharingHelper.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/Classes/Util/SFSDKReachability.h', 'libs/SalesforceSDKCommon/SalesforceSDKCommon/SalesforceSDKCommon.h'
      sdkcommon.prefix_header_contents = ''
      sdkcommon.requires_arc = true

  end

end
