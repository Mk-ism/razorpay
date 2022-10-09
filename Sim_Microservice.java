package com.infosys.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.infosys.model.SimDetails;
import com.infosys.model.SimOffers;
import com.infosys.service.SimService;

@RestController
public class SimController {
	
	@Autowired
	private SimService service;
	@PostMapping(path="/simdetail027")
	public SimDetails getDetails(@RequestBody SimDetails ob) {
		return service.savedetails(ob);
	}
	@PostMapping(path="/offers07")
	public SimOffers getDetails(@RequestBody SimOffers ob) {
		return service.simoffersdetail(ob);
	}
	
	@PostMapping("/siminf/{serviceNumber}/{simNumber}")
	public String GetSimDetails(@PathVariable long serviceNumber,@PathVariable long simNumber)
	{
		String simn;
		String servicen;
		simn=String.valueOf(simNumber);
		servicen=String .valueOf(serviceNumber);
		
		if(simn.matches("^[0-9]{13}$") && servicen.matches("^[0-9]{10}$"))
		{
			long sim_Id=service.ShowSimDetils(serviceNumber, simNumber).getSimId();
			
			
			return service.ShowOffers(sim_Id);
		}
			
		return "";
		
	}
}
