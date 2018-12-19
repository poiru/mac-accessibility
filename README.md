```js
const accessibility = require('mac-accessibility')

// https://developer.apple.com/documentation/applicationservices/1459186-axisprocesstrustedwithoptions
const prompt = false
const result = accessibility.isTrustedAccessibilityClient(prompt)

accessibility.openAccessibilityPrivacySettings()
```
