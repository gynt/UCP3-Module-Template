

return {

  enable = function(self, config)
    log(INFO, "enabling this dll")
    
    self.value = require("UCP3ModuleTemplate.dll")
    
    log(INFO, "result of dll: " .. tostring(self.value))
  end,
  
  disable = function(self, config)
  
  
  end,
  
}