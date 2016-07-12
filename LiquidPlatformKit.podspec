Pod::Spec.new do |s|
  s.name = 'LiquidPlatformKit'
  s.version = '0.8'
  s.license = 'MIT'
  s.summary = 'LPK to Interact with LPS'
  s.homepage = 'https://github.com/LiquidAnalytics/ld-api-examples'
  s.authors = { 'Liquid Analytics Software Team' => 'care@liquidanalytics.com' }
  s.source = { :git => 'https://github.com/LiquidAnalytics/ld-api-examples.git', :tag => s.version }

  s.ios.deployment_target = '8.0'
  s.ios.vendored_frameworks = 'ios/LiquidPlatformKit.framework'
end