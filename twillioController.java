
package com.example.demo;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;


@RestController
@RequestMapping("api/sms")
public class Controller {

    @Autowired
    private TwilioRepository twilioRepository;

    private final Service service;

    @Autowired
    public Controller(Service service) {
        this.service = service;
    }

    @PostMapping
    public void sendSms(@Valid @RequestBody SmsRequest smsRequest) {
        service.sendSms(smsRequest);
    }

    @PostMapping("/whatsapp")
    public void getSms(@RequestBody String message) {
        System.out.println(message);
        String[] newMessage = message.split("&");
        String userId = "+" + newMessage[4].split("=")[1];
        String body =newMessage[6].split("=")[1];
        User u = new User();
        u.setUserId(userId);
        u.setName(body);
        User newUser = twilioRepository.save(u);
        System.out.println("User ID: "+ userId +"\nName: "+body);
    }
}
